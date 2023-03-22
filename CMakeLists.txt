cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(BUILD_TESTS "Build the Mojave tests" OFF)
option(BUILD_BENCHMARK "Build the Mojave benchmarks" OFF)
option(LOGGING "The engine provides debugging info" OFF)

enable_testing()

project(Mojave VERSION 1.0)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -DDEBUG -g") 

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DRELEASE -Ofast") 

add_executable(
    mojave 
    src/main.cpp 
    src/Bitboard.cpp 
    src/ChessboardSearch.cpp 
    src/BoardConcepts.cpp 
    src/Moves.cpp src/Chessboard.cpp 
    src/ChessboardEvaluation.cpp 
    src/Interface.cpp 
    src/ChessboardMoveGeneration.cpp 
    src/ChessboardZobrist.cpp 
    src/ChessboardBoardManipulation.cpp 
    src/ChessboardDisplay.cpp 
    src/ChessboardFen.cpp 
    src/InterfaceCLI.cpp 
    src/InterfaceUCI.cpp
)

add_library(bitboard STATIC src/Bitboard.cpp)

add_library(boardconcepts STATIC src/BoardConcepts.cpp)

add_library(moves STATIC src/Moves.cpp)

target_link_libraries(moves bitboard)
target_link_libraries(moves boardconcepts)

add_library(chessboard STATIC 
    src/Chessboard.cpp 
    src/ChessboardSearch.cpp 
    src/ChessboardEvaluation.cpp 
    src/ChessboardMoveGeneration.cpp 
    src/ChessboardZobrist.cpp 
    src/ChessboardBoardManipulation.cpp 
    src/ChessboardDisplay.cpp 
    src/ChessboardFen.cpp
)

target_link_libraries(chessboard bitboard)
target_link_libraries(chessboard boardconcepts)
target_link_libraries(chessboard moves)

if (DEBUG)
    # GOOGLE LOGGING LIBRARY 

    find_package(glog REQUIRED)
    target_link_libraries(mojave glog)

    # BENCHMARKS LIBRARY 
   
    find_package(hayai REQUIRED)

    # GOOGLES TESTING LIBRARY 

    find_package(GTest REQUIRED)
    
    include(GoogleTest)

    add_executable(tests 
        tests/unit_tests/main.cpp 
        tests/unit_tests/bitboard_test.cpp 
        tests/unit_tests/boardconcepts_test.cpp 
        tests/unit_tests/moves_test.cpp 
        tests/unit_tests/chessboard_test.cpp
    )
    
    
    target_link_libraries(tests GTest::gtest)
    
    target_link_libraries(tests bitboard)
    target_link_libraries(tests boardconcepts)
    target_link_libraries(tests moves)
    target_link_libraries(tests chessboard)

    gtest_discover_tests(tests)
endif()
