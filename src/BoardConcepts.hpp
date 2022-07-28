/*

    this file contains some definititions for concepts relating to chess

    Translates Human understanding of board concepts for example rank and file
    to computers interpreation of internal board representation in this case bitboards

*/

#pragma once

#include <iostream>
#include <map>
#include <cmath>

extern std::string PieceAsciiSymbols[12];
extern std::string SqaureMappingArray[64];

const uint64_t FILE_H = 9259542123273814144ULL;
const uint64_t FILE_A = 72340172838076673ULL;
const uint64_t FILE_B = 144680345676153346ULL;
const uint64_t FILE_F = 2314885530818453536ULL;
const uint64_t FILE_E = 1157442765409226768ULL;
const uint64_t FILE_D = 578721382704613384ULL;
const uint64_t FILE_C = 289360691352306692ULL;
const uint64_t FILE_G = 4629771061636907072ULL;

//const uint64_t *FileIsolatorArray[8] = {&FILE_A, &FILE_B, &FILE_C, &FILE_D, &FILE_E, &FILE_F, &FILE_G, &FILE_H};


const uint64_t RANK_2 = 0xFF000000000000;
const uint64_t RANK_7 = 0xFF00;
const uint64_t RANK_8 = 0xFF;
const uint64_t RANK_1 = 0xFF00000000000000;
const uint64_t RANK_6 = 0xFF0000;
const uint64_t RANK_3 = 0xFF0000000000;
const uint64_t RANK_5 = 0xFF000000;
const uint64_t RANK_4 = 0xFF00000000;

//const uint64_t *RankIsolatorArray[8] = {&RANK_1, &RANK_2, &RANK_3, &RANK_4, &RANK_5, &RANK_6, &RANK_7, &RANK_8};

const uint64_t WhiteQueenCastleBitboard = 0xE00000000000000;
const uint64_t WhiteKingCastleBitboard = 0x6000000000000000;
const uint64_t BlackKingCastleBitboard = 0xE;
const uint64_t BlackQueenCastleBitboard = 0x60;

// white represented by 0
//black represented by 1
enum Sides {
    white, black
};

// assign each peice a numerical value
enum Pieces {
    BlackPawn, BlackBishop, BlackKing, BlackQueen, BlackKnight, BlackRook,
    WhitePawn, WhiteBishop, WhiteKing, WhiteQueen, WhiteKnight, WhiteRook
};

void PrintPiecetype(int PieceType);

// this struct contains a moves data
typedef struct Move{
    int Origin;
    int Destination;
    int Side;
    int PieceType;
    std::string AlgerbraicNotation;

    Move(int OriginValue, int DestinationValue, int SideValue, int PieceTypeValue) : Origin(OriginValue), Destination(DestinationValue), Side(SideValue), PieceType(PieceTypeValue)
    {
        CreateAlgerbraicNotation();
    }

    Move(std::string AlgerbraicNotation);

    void PrintMove();

    private:
        void CreateAlgerbraicNotation();
} Move;


// this allows us to get the position of a square notation in a 64 bit int
enum BoardSquare {
  a8, b8, c8, d8, e8, f8, g8, h8,
  a7, b7, c7, d7, e7, f7, g7, h7,
  a6, b6, c6, d6, e6, f6, g6, h6,
  a5, b5, c5, d5, e5, f5, g5, h5,
  a4, b4, c4, d4, e4, f4, g4, h4,
  a3, b3, c3, d3, e3, f3, g3, h3,
  a2, b2, c2, d2, e2, f2, g2, h2,
  a1, b1, c1, d1, e1, f1, g1, h1
};

enum Rays {
    North, Northeast, East, Southeast,
    South, Southwest, West, Northwest
};

