#pragma once

#include <cstdint>
#include <string>
#include <cstring>
#include <iostream>
#include <chrono>
#include <sys/types.h>
#include <vector>
#include <thread>
#include <random>

#include "Bitboard.hpp"
#include "BoardConcepts.hpp"
#include "Moves.hpp"
#include "BoardConcepts.hpp"
#include "Bitboard.hpp"

// create a chessboard object
// represented by bitboards objects
class Chessboard {
    private:
    // * Non specific bit boards
        // bit board 1s represent a piece of either colour
        uint64_t WhiteBlackBitBoard = 0ULL;

        // bit board 1s represent a white piece
        uint64_t WhiteBitBoard = 0ULL;

        // bit bors 1s represent a black piece
        uint64_t BlackBitBoard = 0ULL;

    // * side bitboard array

        uint64_t *SideBitboardArray[2] = {&WhiteBitBoard, &BlackBitBoard};
    
    // * Specific Black bit boards 
        // bitboard 1s represent a black king
        uint64_t BlackKingBitBoard = 0ULL;

        // bitboard 1s represent a black Bishop
        uint64_t BlackBishopBitBoard = 0ULL;

        // bitboard 1s represent a black Rook
        uint64_t BlackRookBitBoard = 0ULL;

        // bitboard 1s represent a black Pawn
        uint64_t BlackPawnBitBoard = 0ULL;

        // bitboard 1s represent a black Knight
        uint64_t BlackKnightBitBoard = 0ULL;

        // bitboard 1s represent a black Queen
        uint64_t BlackQueenBitBoard = 0ULL;

        uint64_t *BlackBitboardArry[6] = {&BlackPawnBitBoard, &BlackBishopBitBoard, &BlackKingBitBoard, &BlackQueenBitBoard, &BlackKnightBitBoard, &BlackRookBitBoard};

    // * Specific white bit boards

        // bitboard 1s represent a white king
        uint64_t WhiteKingBitBoard = 0ULL;

        // bitboard 1s represent a white Bishop
        uint64_t WhiteBishopBitBoard = 0ULL;

        // bitboard 1s represent a white Rook
        uint64_t WhiteRookBitBoard = 0ULL;

        // bitboard 1s represent a white Pawn
        uint64_t WhitePawnBitBoard = 0ULL;

        // bitboard 1s represent a white Knight
        uint64_t WhiteKnightBitBoard = 0ULL;

        // bitboard 1s represent a white Queen
        uint64_t WhiteQueenBitBoard = 0ULL;

        uint64_t *WhiteBitboardArry[6] = {&WhitePawnBitBoard, &WhiteBishopBitBoard, &WhiteKingBitBoard, &WhiteQueenBitBoard, &WhiteKnightBitBoard, &WhiteRookBitBoard};

        uint64_t CastleRightsBitboard[2][2] = {{WhiteQueenCastleBitboard, WhiteKingCastleBitboard},{BlackQueenCastleBitboard, BlackKingCastleBitboard}};

    // * array of piece bitboards

        // this allows us to get a bitboard by using PieceType Enum

        /* Example

            PieceTypeBitboardArray[WhitePawn].Addbit(e4);

            notice how due to the enum we can use human readable text and not remember the numbers assigned to 
            each square or piece type!

        */

        uint64_t *PieceTypeBitboardArray[12] = {&BlackPawnBitBoard, &BlackBishopBitBoard, &BlackKingBitBoard, &BlackQueenBitBoard, &BlackKnightBitBoard, &BlackRookBitBoard, &WhitePawnBitBoard, &WhiteBishopBitBoard, &WhiteKingBitBoard, &WhiteQueenBitBoard, &WhiteKnightBitBoard, &WhiteRookBitBoard};

    // * offsets for calculating where pieces can capture

    /*     
        int BlackPawnoffsetArray[2] = {-9,-7};
        int KnightOffsetArray[8] = {-17, -15, -6, 6, 10, -10, 17, 15};
        int BishopOffsetArray[4] = {9,7,-9,-7};
        int RookOffsetArray[4] = {-1,1,8,-8};
        int QueenOffsetArray[8] = {-1,1,-8,8,9,-7,7,-9};
        int WhitePawnoffsetArray[2] = {9,7};
        int KingOffset[8] = {8, -8, 9, -9, -7, 7, 1, -1};
    */

    // you can use this array to get the offset of a peice type black bishop is simply - PieceOffsets[BlackBishop]

        /*
        enum Pieces {
            BlackPawn, BlackBishop, BlackKing, BlackQueen, BlackKnight, BlackRook,
            WhitePawn, WhiteBishop, WhiteKing, WhiteQueen, WhiteKnight, WhiteRook
        };
        */

        // a vector which stores move structs
        std::vector<Move> Moves;

        // side to move
        // this will be modified when the constructer calls the parse FEN function
        //true is white
        bool SideToMove = white;

        // castling rights
        // these will be modified when the constructer calls the parse FEN function
        int BlackQueenCastleRights = 1;
        int BlackKingCastleRights = 1;
        int WhiteQueenCastleRights = 1;
        int WhiteKingCastleRights = 1;

        int CastleRightsArray[2][2] = {{WhiteQueenCastleRights, WhiteKingCastleRights}, {BlackQueenCastleRights, BlackKingCastleRights}};
       
        /*
         * randomly generated numbers used for zobrist hashing 
        */
        int ZobristPieceSquareValues[64][12];
        int ZobristBlackToMove;
        int ZobristEnPassant[8];
        int ZobristCastlingRights[4];
    public:
        uint64_t GetKingMoves(int square, int side);
        uint64_t GetKnightMoves(int square, int side);
        uint64_t GetPawnMoves(int square, int side);
        
        uint64_t ClassicalGenerateRookMoves(int square, int side);
        uint64_t ClassicalGenerateBishopMoves(int Square, int side);
        uint64_t ClassicalGenerateQueenMoves(int square, int side);        

        uint64_t (Chessboard::Chessboard::*MoveCalculatingFunctions[6]) (int square, int side) {&Chessboard::GetPawnMoves, &Chessboard::ClassicalGenerateBishopMoves, &Chessboard::GetKingMoves, &Chessboard::ClassicalGenerateQueenMoves, &Chessboard::GetKnightMoves, &Chessboard::ClassicalGenerateRookMoves};
    
        int GetPieceType(int Square);
        void PutPiece(int Square, int PieceType);
        void WipePiece(int Square);

        void ClearBoard();

        Move CreateMoveFromAlgerbraicNotation(std::string AlgerbraicNotation);

        int DoMove(Move MoveToDo);
        int UndoLastMove();

        void ZobristInit();
        int ZobristHash();

        std::vector<Move> GetAllSidesMoves(int Side);
        std::vector<Move> GetAllMoves();

        // FEN handling
        void ParseFEN(std::string FEN);

        //class constructer        
        Chessboard(std::string FEN);
        Chessboard();

        // EVAL functions
        int EvaluateMobility();
        int EvaluateMaterial();
        int Evaluate();

        //SEARCH functions
        int SearchNegaMax(int depth);
        Move SearchRandom();

        void PrintChesssboard();
        void ShowMove(Move MoveToShow);
};
