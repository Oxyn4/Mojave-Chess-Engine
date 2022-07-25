
#include "../../src/Moves.hpp"

#include <hayai/hayai.hpp>

#include <gtest/gtest.h>

BENCHMARK(moves, PrecomputateKingMoves, 10, 100) 
{
    PrecomputateKingMoves();
};

BENCHMARK(moves, PrecomputatePawnMoves, 10, 100) 
{
    PrecomputatePawnMoves();
};

BENCHMARK(moves, PrecomputatePawnAttacks, 10 , 100) 
{
    PrecomputatePawnAttacks();
};

BENCHMARK(moves, PrecomputateKnightMoves, 10 , 100) 
{
    PrecomputateKnightMoves();
};

BENCHMARK(moves, GenerateRaysArray, 10 , 100) 
{
    GenerateRaysArray();
};


