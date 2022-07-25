
#include "Interface.hpp"
#include "Moves.hpp"

/*
    welcome to the entry point for mojave chess engine

    this file contains driver code for a standard cpp program (main function)
*/


int main() {

    MoveGenerationInit();

    InterfaceLoop();

    return EXIT_SUCCESS;    
}
