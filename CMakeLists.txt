cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(BUILD_TESTS "Build the Mojave tests" OFF)
option(BUILD_BENCHMARK "Build the Mojave benchmarks" OFF)
option(DEBUG "The engine provides debugging info" OFF)

enable_testing()

project(Mojave VERSION 1.0)

if (DEBUG)
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -DDEBUG -g")
else()
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Ofast")
endif()

add_executable(mojave src/main.cpp src/Bitboard.cpp src/ChessboardSearch.cpp src/BoardConcepts.cpp src/Moves.cpp src/Chessboard.cpp src/ChessboardEvaluation.cpp src/Interface.cpp src/ChessboardMoveGeneration.cpp src/ChessboardZobrist.cpp src/ChessboardBoardManipulation.cpp src/InterfaceCLI.cpp src/InterfaceUCI.cpp)

add_library(bitboard STATIC src/Bitboard.cpp)

add_library(boardconcepts STATIC src/BoardConcepts.cpp)

add_library(moves STATIC src/Moves.cpp)

add_library(chessboard STATIC src/Chessboard.cpp src/ChessboardSearch.cpp src/ChessboardEvaluation.cpp src/ChessboardMoveGeneration.cpp src/ChessboardZobrist.cpp src/ChessboardBoardManipulation.cpp)

target_link_libraries(moves bitboard)
target_link_libraries(moves boardconcepts)

if (BUILD_BENCHMARK)
    add_executable(benchmark tests/benchmark/main.cpp tests/benchmark/moves_benchmark.cpp)

    target_link_libraries(benchmark bitboard)
    target_link_libraries(benchmark boardconcepts)
    target_link_libraries(benchmark moves)

endif()

if (BUILD_TESTS)
    find_library(GTEST gtest)

    if (GTEST)

        include(GoogleTest)

        add_executable(tests tests/unit_tests/main.cpp tests/unit_tests/bitboard_test.cpp tests/unit_tests/boardconcepts_test.cpp tests/unit_tests/moves_test.cpp)
        
        target_link_libraries(tests gtest)
        
        target_link_libraries(tests bitboard)
        target_link_libraries(tests boardconcepts)
        target_link_libraries(tests moves)

        gtest_discover_tests(tests)
    
    else()
        message(FATAL_ERROR "cannot find google test library")

    endif()
endif()
