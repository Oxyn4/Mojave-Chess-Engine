#pragma once

#include <iostream>
#include <cstdint>
#include <vector>


// create a btboard
// see: https://www.chessprogramming.org/Bitboards
// bit minipulation
void AddBit(uint64_t Board, int Square);
void DelBit(uint64_t Board, int Square);
int GetBit(uint64_t Board, int Square);

// pop count functions
bool IsEmpty(uint64_t Board);
int PopulationCount(uint64_t Board);

// orientation minipulation
uint64_t FlipVertical(uint64_t Board);
uint64_t FlipHorizontal(uint64_t Board);

// bitscan funciton
int BitScanLSB(uint64_t Board);
int BitscanMSB(uint64_t Board);

// visuiation function
void PrintBitboard(uint64_t Board);
void PrintBitboard_Raw(uint64_t Board);
void PrintBitboard_Table(uint64_t Board);
