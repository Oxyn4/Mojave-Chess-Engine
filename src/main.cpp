
#include "Bitboard.hpp"
#include "BoardConcepts.hpp"
#include "Chessboard.hpp"
#include "Interface.hpp"
#include "Moves.hpp"
#include <vector>
#include <filesystem>

#include <glog/logging.h>

/*
welcome to the entry point for mojave chess engine

    this file contains driver code for a standard cpp program (main function)
*/


int main(int argc, char *argv[]) 
{
    #ifdef DEBUG
        std::filesystem::create_directories("logs/");
    
        FLAGS_log_dir = "logs/";
    
        google::InitGoogleLogging(argv[0]);

        LOG(INFO) << "initialised glog library\n";
    #endif

    MoveGenerationInit();

    ParseCommandLineArguments(argc, argv);

    InterfaceLoop();

    return EXIT_SUCCESS;    
}
