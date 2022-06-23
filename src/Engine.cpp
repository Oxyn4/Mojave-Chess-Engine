
#include "Chessboard.h"
#include "BoardConcepts.h"
#include "Moves.h"
#include "Bitboard.h"
#include "Interface.h"

#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <thread>

/*
    welcome to the entry point for mojave chess engine

    this file contains driver code for a standard cpp program (main function)
*/


int main() {

    MoveGenerationInit();

    InterfaceLoop();

    return EXIT_SUCCESS;    
}
