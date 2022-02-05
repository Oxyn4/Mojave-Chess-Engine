/*

    this file contains some definititions for concepts relating to chess

    for example:

        instead of using "1" or "0" to refer to "white" or "black"
        we can use "white" or "black" and the sides enum will convert it
    
    this concept is the same for the other definititions

*/

#pragma once

#include <iostream>

const int64_t FILE_H = 9259542123273814144ULL;
const int64_t FILE_A = 72340172838076673ULL;
const int64_t FILE_B = 144680345676153346ULL;
const int64_t FILE_G = 4629771061636907072ULL;
const uint64_t RANK_2 = 0xFF000000000000;
const uint64_t RANK_7 = 0xFF00;
const uint64_t RANK_8 = 0xFF;
const uint64_t RANK_1 = 0xFF00000000000000;
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

// this struct contains a moves data
typedef struct Move{
    int Origin;
    int Destination;
    int Side;
    int PieceType;

    Move(int OriginValue, int DestinationValue, int SideValue, int PieceTypeValue) : Origin(OriginValue), Destination(DestinationValue), Side(SideValue), PieceType(PieceTypeValue)
    {
        Origin = OriginValue;
        Destination = DestinationValue;
        Side = SideValue;
        PieceType = PieceTypeValue;  
    }
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
