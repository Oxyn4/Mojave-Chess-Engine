
#include "Bitboard.hpp"
#include "BoardConcepts.hpp"
#include "Chessboard.hpp"
#include "Interface.hpp"
#include "Moves.hpp"
#include <vector>

#include <glog/logging.h>

/*
welcome to the entry point for mojave chess engine

    this file contains driver code for a standard cpp program (main function)
*/


int main(int argc, char *argv[]) 
{

    google::InitGoogleLogging(argv[0]);


    MoveGenerationInit();

    ParseCommandLineArguments(argc, argv);

    InterfaceLoop();

    return EXIT_SUCCESS;    
}
