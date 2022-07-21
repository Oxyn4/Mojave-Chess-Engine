cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Mojave VERSION 1.0)

add_executable(mojave src/main.cpp src/Bitboard.cpp src/Search.cpp src/BoardConcepts.cpp src/Moves.cpp src/Chessboard.cpp src/Evaluation.cpp src/Interface.cpp)

add_library(bitboard STATIC src/Bitboard.cpp)

add_library(boardconcepts STATIC src/BoardConcepts.cpp)

find_library(GTEST gtest)

if (GTEST)

    include(GoogleTest)

    add_executable(bitboard_test tests/bitboard_test.cpp)
    target_link_libraries(bitboard_test gtest)
    target_link_libraries(bitboard_test bitboard)
    target_link_libraries(bitboard_test boardconcepts)

    add_executable(boardconcepts_test tests/boardconcepts_test.cpp)
    target_link_libraries(boardconcepts_test gtest)
    target_link_libraries(boardconcepts_test boardconcepts)

endif()

