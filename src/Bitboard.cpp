#include "Bitboard.h"

/*

    This file contains many useful functions that abstract binary operations

*/

void AddBit(uint64_t *Board, int Square) {

    *Board |= (1ULL << Square) ? *Board ^= (1ULL << Square) : 0;            

}

void DelBit(uint64_t *Board, int Square) {
    *Board ^= (1ULL << Square);

    //*Board &= ~((1 << Square));
}

int GetBit(uint64_t *Board, int Square) {
    //int BitStatus = (*Board & ( 1 << Square )) >> Square;
    int BitStatus = ((*Board>>Square) & 1);
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
    while (Board != 0) {
        Count++;     
    Board &= Board - 1;           
    }
    return Count;
}

// display an ascii art version of a bitboard object
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
int BitScanLSB(uint64_t *Board) {
    return  ((__builtin_ffsll(*Board)  - 1));
}

//msb
int BitscanMSB(uint64_t *Board) {
    return (63 - __builtin_clzll(*Board));
}


int NotSide(int side) 
{
    return side ? 0 : 1;
}
