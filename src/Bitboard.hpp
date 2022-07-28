#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <stdio.h>

typedef uint64_t Bitboard;

// create a bitboard
// see: https://www.chessprogramming.org/Bitboards
// bit manipulation
void AddBit(uint64_t *Board, int Square);
void DelBit(uint64_t *Board, int Square);
int GetBit(uint64_t *Board, int Square);


// pop count functions
bool IsEmpty(uint64_t Board);
int PopulationCount(uint64_t Board);

// orientation manipulation
uint64_t FlipVertical(uint64_t Board);
uint64_t FlipHorizontal(uint64_t Board);

// bitscan function
int BitScanLSB(uint64_t *Board);
int BitscanMSB(uint64_t *Board);

void ResetLSB(uint64_t *Board);
void ResetMSB(uint64_t *Board);

// visualization function
void PrintBitboard(uint64_t Board);
void PrintBitboard_Raw(uint64_t Board);
void PrintBitboard_Table(uint64_t Board);

//misc functions

// returns the opp side to one given
int NotSide(int side);
