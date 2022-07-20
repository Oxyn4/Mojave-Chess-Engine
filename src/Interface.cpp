/*

    contains code for interfacing with the engine via a user interface

    manages one or more chessboard objectes
*/

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#include "Bitboard.hpp"
#include "BoardConcepts.hpp"
#include "Chessboard.hpp"
#include "Interface.hpp"

int communicationstatus = 1;

// list of commands sent from GUI
std::vector<std::string> CommandHistory;

int IsPositionInited = 0;

std::unique_ptr<Chessboard> Board;

void ParseInterfaceCommand(std::vector<std::string>& TokenVector) 
{
    for (int TokenVectorIterator=0; TokenVectorIterator < TokenVector.size(); TokenVectorIterator++) 
    {
        if (TokenVector[TokenVectorIterator] == "uci" || TokenVector[TokenVectorIterator] == "uci\n") 
        {
            std::cout << "id name Mojave\n";
            std::cout << "id author Jacob Evans\n";
            std::cout << "uciok\n";   
        }   
        
        if (TokenVector[TokenVectorIterator] == "isready\n" || TokenVector[TokenVectorIterator] == "isready")
        {
            std::cout << "readyok\n";
        }

        if (TokenVector[TokenVectorIterator] == "position")
        {

            if (TokenVector[TokenVectorIterator+1] == "startpos") 
            {
                Board.reset(new Chessboard("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"));
            } 
            else 
            {
                Board.reset(new Chessboard(TokenVector[TokenVectorIterator+1]));
            }       

            if (TokenVector[TokenVectorIterator+2] == "moves") 
            {
                for (int MovesMadeIterator=(TokenVectorIterator+3); MovesMadeIterator < TokenVector.size(); MovesMadeIterator++) 
                {
                    Move MoveMade(TokenVector[MovesMadeIterator]);

                    Board->DoMove(MoveMade);        
                }
                Board->PrintChesssboard();
            }
        }

        if (TokenVector[TokenVectorIterator] == "go") 
        {
            Move Bestmove = Board->SearchRandom();

            Board->PrintChesssboard();

            Board->DoMove(Bestmove);

            Board->PrintChesssboard();

            std::cout << "bestmove " << Bestmove.AlgerbraicNotation << "\n";
        }
    }
}


void InterfaceLoop() 
{   
    while (communicationstatus == 1) 
    {
        char UCI_Command[50];

        std::cin.getline(UCI_Command, 50);

        std::string UCI_CommandString = UCI_Command;

        std::vector<std::string> TokenVector;

        std::istringstream CommandStringStream(UCI_CommandString);

        std::string Token;

        while (CommandStringStream >> Token)
        {
            TokenVector.push_back(Token);
        }
    
        ParseInterfaceCommand(TokenVector);
    }
}
