#pragma once


// stdc++ headers
#include <iostream>
#include <chrono>


// project local headers
#include "BoardConcepts.hpp"
#include "Bitboard.hpp"

extern uint64_t KnightMoves[64];
extern uint64_t KingMoves[64];
extern uint64_t PawnAttacks[2][64];
extern uint64_t PawnMoves[2][64];
extern uint64_t RaysArray[64][8];


void PrecomputateKnightMoves();
void PrecomputateKingMoves();
void PrecomputatePawnAttacks();
void PrecomputatePawnMoves();
void GenerateRaysArray();
void MoveGenerationInit();
