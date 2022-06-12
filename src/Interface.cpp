/*

    contains code for interfacing with the engine via GUI

*/

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#include "Bitboard.h"
#include "BoardConcepts.h"
#include "Chessboard.h"
#include "Interface.h"

int communicationstatus = 1;

// list of commands sent from GUI
std::vector<std::string> CommandHistory;

// games the engine is currently running
std::vector<Chessboard> GameList;

std::vector<std::string> TokenVector;

void ParseInterfaceCommand(std::string Command) {


    std::string Token;

    // converts string to sstream
    std::istringstream TokenStream(Command);

    // loop through words found in a string
    // load into a vector
    while (TokenStream >> Token) {
        TokenVector.push_back(Token);
    }

    std::cout << TokenVector.size() << "\n";

    if (TokenVector[0] == "uci" || TokenVector[0] == "uci\n") 
    {
        std::cout << "id name Mojave\n";
        std::cout << "id author Jacob Evans\n";
        std::cout << "uciok\n";   
    }    

    if (TokenVector[0] == "isready\n" || TokenVector[0] == "isready") 
    {
        std::cout << "readyok\n";
    }

    if (TokenVector[0] == "position")
    {
            /*
            std::unique_ptr<Chessboard> Board;

            if (TokenVector[TokenVectorPosition+1] != "startpos") 
            {    
                Board.reset(new Chessboard(TokenVector[TokenVectorPosition+1]));
            }
            else 
            {
                Board.reset(new Chessboard("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"));
            }
            */
    }

    if (TokenVector[0] == "go") 
    {

            //Move Bestmove = Board->SearchRandom();

            //std::cout << "bestmove " << Bestmove.AlgerbraicNotation << "\n";
    }
    
    // TODO: add rest of UCI commands
    
    

    // clear the vector ready for next command
    TokenVector.clear();
}

void InterfaceLoop() 
{    
    while (communicationstatus == 1) 
    {
        std::string Command;
        std::cin >> Command;

        ParseInterfaceCommand(Command);

        CommandHistory.push_back(Command);
    }    
}
