
#include "Chessboard.hpp"
#include "BoardConcepts.hpp"
#include "Moves.hpp"
#include "Bitboard.hpp"
#include "Interface.hpp"

/*
    welcome to the entry point for mojave chess engine

    this file contains driver code for a standard cpp program (main function)
*/


int main() {

    MoveGenerationInit();

    InterfaceLoop();

    return EXIT_SUCCESS;    
}
