
#include <iostream>
#include <string>

#include "uci.h"
#include "BoardConcepts.h"
#include "Chessboard.h"

int communicationstatus = 1;

void ParseCommand(std::string Command, Chessboard &Board) {

    if (Command == "uci\n") {

        std::cout << "id name Mojave 1.1\n";
        std::cout << "id author Jacob Evans\n";
        std::cout << "uciok\n";
    }

    if (Command == "isready\n") {
        std::cout << "readyok\n";
    }

    if (Command == "exit\n")
    {
        exit(EXIT_FAILURE);
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