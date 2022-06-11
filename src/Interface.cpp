/*

    contains code for interfacing with the engine via GUI

*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#include "BoardConcepts.h"
#include "Chessboard.h"
#include "Interface.h"

int communicationstatus = 1;

// list of commands sent from GUI
std::vector<std::string> CommandHistory;

// games the engine is currently running
std::vector<Chessboard> GameList;

void ParseInterfaceCommand(std::string Command) {

    std::vector<std::string> TokenVector;

    std::string Token;

    // converts string to sstream
    std::istringstream TokenStream(Command);

    // loop through words found in a string
    // load into a vector
    while (TokenStream >> Token) {
        TokenVector.push_back(Token);
    }

    for (int TokenVectorPosition; TokenVectorPosition < TokenVector.size(); TokenVectorPosition++) 
    {
        if (TokenVector[TokenVectorPosition] == "uci" || TokenVector[TokenVectorPosition] == "uci\n") {
            std::cout << "id name Mojave\n";
            std::cout << "id author Jacob Evans\n";
            std::cout << "uciok\n";   
        }    

        if (TokenVector[TokenVectorPosition] == "isready\n" || TokenVector[TokenVectorPosition] == "isready") 
        {
            std::cout << "readyok\n";
        }

        // uci position command
        /*if (TokenVector[TokenVectorPosition] == "position")
        {
            // position <FEN> <Move1> <Move2> etc

            // startpos is a valid token a variable for starting fen
            if (TokenVector[TokenVectorPosition + 1] == "startpos") 
            {
                GameList.emplace_back("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
            } else {
                GameList.emplace_back(TokenVector[TokenVectorPosition+1]);
            }

            // if there are any tokens after the FEN
            // loop over them and apply them to the board 
            
            if (TokenVectorPosition+2 <= TokenVector.size())
            {
                for (int MovesMade=TokenVectorPosition+2; MovesMade < TokenVector.size(); MovesMade++) 
                {
                    // convert move from LongAlgerbraicNotation to a format mojave functions can understand
                    Move AppliedMove = LongAlgerbraicNotationToMojaveFormat(TokenVector[MovesMade]);        
                
                    GameList[0].DoMove(AppliedMove);
                }
            }
            

            if (TokenVector[TokenVectorPosition+2] == "moves") 
            {
                for (int MovesMade=TokenVectorPosition+2; MovesMade < TokenVector.size(); MovesMade++) 
                {
                    //ove AppliedMove = LongAlgerbraicNotationToMojaveFormat(TokenVector[MovesMade]);

                   //ameList[0].DoMove(AppliedMove);
                }    
            }
       */

        if (TokenVector[TokenVectorPosition] == "go") 
        {
            Chessboard Board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

            Move Bestmove = Board.SearchRandom();

            std::cout << "bestmove " << Bestmove.AlgerbraicNotation << "\n";
        }
    
    // TODO: add rest of UCI commands
    
    }

    // clear the vector ready for next command
    TokenVector.clear();
}

void InterfaceLoop() {    
    while (communicationstatus == 1) {
        std::string Command;
        std::cin >> Command;

        ParseInterfaceCommand(Command);

        CommandHistory.push_back(Command);
    }    
}
