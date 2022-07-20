cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(mojave VERSION 1.0)
add_executable(mojave src/main.cpp src/Bitboard.cpp src/Search.cpp src/BoardConcepts.cpp src/Moves.cpp src/Chessboard.cpp src/Evaluation.cpp src/Interface.cpp)
