
#include <iostream>
#include <string>

#include "uci.h"
#include "BoardConcepts.h"
#include "Chessboard.h"

int communicationstatus = 1;

void ParseCommand(std::string Command, Chessboard Board) {
    if (Command == "exit\n")
    {
        std::cout << "Exiting\n";    
    }
}

void UCILoop(Chessboard Board) {    
    while (communicationstatus == 1) {
        std::string Command;
        std::cin >> Command;

        ParseCommand(Command, Board);
    }    
}