#include "Bitboard.h"
#include <iostream>
#include <vector>
#include <stdio.h>

const int index64[64] = {
    0,  1, 48,  2, 57, 49, 28,  3,
   61, 58, 50, 42, 38, 29, 17,  4,
   62, 55, 59, 36, 53, 51, 43, 22,
   45, 39, 33, 30, 24, 18, 12,  5,
   63, 47, 56, 27, 60, 41, 37, 16,
   54, 35, 52, 21, 44, 32, 23, 11,
   46, 26, 40, 15, 34, 20, 31, 10,
   25, 14, 19,  9, 13,  8,  7,  6
};

static const int lookup67[67+1] = {
      64,  0,  1, 39,  2, 15, 40, 23,
       3, 12, 16, 59, 41, 19, 24, 54,
       4, -1, 13, 10, 17, 62, 60, 28,
      42, 30, 20, 51, 25, 44, 55, 47,
       5, 32, -1, 38, 14, 22, 11, 58,
      18, 53, 63,  9, 61, 27, 29, 50,
      43, 46, 31, 37, 21, 57, 52,  8,
      26, 49, 45, 36, 56,  7, 48, 35,
       6, 34, 33, -1 };

void AddBit(uint64_t Board, int Square) {

    Board |= (1ULL << Square) ? Board ^= (1ULL << Square) : 0;            

}

void DelBit(uint64_t Board, int Square) {
    Board ^= (1ULL << Square);
}

int GetBit(uint64_t Board, int Square) {
    int BitStatus = (Board & ( 1 << Square )) >> Square;
    return BitStatus;             
}

bool IsEmpty(uint64_t Board) {
    if (Board == 0) {
        return true;
    } else {
        return false;
    }
    return false;
}

// recursively reset the lsb and add to a counter
// when bitboard is empty return the counter
int PopulationCount(uint64_t Board) {
    int Count = 0;
    while (Board) {
        Count++;     
        Board &= Board - 1;           
    }
    return Count;
}

// display an ascii art version of a biboard object
void PrintBitboard(uint64_t Board) {
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            // formula for converting row and colum to index 
            // rank * 8 + file
            int square = rank * 8 + file;
            if (file == 0) {
                std::cout << 8 - rank << " " << "|" << " ";
            }
            int OneOrZero = ((Board & (1ULL << square)) ? 1 : 0);
            if (OneOrZero == 1) {
                std::cout << "1 ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "    ---------------" << "\n";
    std::cout << "    a b c d e f g h" << "\n";
    //cout << "current bitboard: " << self << endl;
}

void PrintBitboard_Raw(uint64_t Board) 
{
    std::cout << std::endl;
    for (int BitIteraotr = 0; BitIteraotr < 64; BitIteraotr++)
    {
        int OneOrZero = ((Board & (1ULL << BitIteraotr)) ? 1 : 0);
        std::cout <<  OneOrZero;
    }
    std::cout << std::endl;
}

void PrintBitboard_Table(uint64_t Board) 
{
    std::cout << std::endl;
    std::cout << " | e8 | e7 |" << "\n";

    for (int Number = 0; Number < 64; Number++)
    {
        if (Number < 10) {
            std::cout << " |  " << Number;
        } else {
            std::cout << " | " << Number;
        }
    }

    std::cout << " |";
    std::cout << std::endl;

    for (int BitIteraotr = 0; BitIteraotr < 64; BitIteraotr++)
    {
        int OneOrZero = ((Board & (1ULL << BitIteraotr)) ? 1 : 0);
    
        if (BitIteraotr < 10) {
            std::cout << " |  " << OneOrZero;
        } else {
            std::cout << " | " << OneOrZero << " ";
        }
    }

    std::cout << " |";
    std::cout << std::endl;
}

uint64_t FlipVertical(uint64_t Board) {
    const uint64_t k1 = 0x00FF00FF00FF00FF;
    const uint64_t k2 = 0x0000FFFF0000FFFF;

    Board = ((Board >>  8) & k1) | ((Board & k1) <<  8);
    Board = ((Board >> 16) & k2) | ((Board & k2) << 16);
    Board = ( Board >> 32)       | ( Board       << 32);
    return Board;
}

uint64_t FlipHorizontal(uint64_t Board) {
    const uint64_t k1 = 0x5555555555555555;
    const uint64_t k2 = 0x3333333333333333;
    const uint64_t k4 = 0x0f0f0f0f0f0f0f0f;
    Board = ((Board >> 1) & k1) +  2*(Board & k1);
    Board = ((Board >> 2) & k2) +  4*(Board & k2);
    Board = ((Board >> 4) & k4) + 16*(Board & k4);
    return Board;
}

//lsb
int BitScanLSB(uint64_t Board) {
    return  ((__builtin_ffsll(Board)  - 1));
}

//msb
int BitscanMSB(uint64_t Board) {
    return (63 - __builtin_clzll(Board));
}

std::vector<int> GetAllBits(uint64_t Board) {
    
    std::vector<int> BitVector;

    while (Board != 0)
    {
        int LSBIndex = BitScanLSB(Board);

        BitVector.push_back(LSBIndex);

        Board &= Board - 1;
    }

    return BitVector;
    
}

