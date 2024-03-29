#include "Bitboard.hpp"
#include "BoardConcepts.hpp"
#include "Chessboard.hpp"

/*
    get the type of piece on a certain square 
 
*/
int Chessboard::GetPieceType(int Square) 
{
    for (int PieceTypeBitboardArrayIterator=0; PieceTypeBitboardArrayIterator < 12; PieceTypeBitboardArrayIterator++) 
    {
        if (GetBit(PieceTypeBitboardArray[PieceTypeBitboardArrayIterator], Square) == 1 )
        {
            return PieceTypeBitboardArrayIterator;
        }
    }
    return -1;
}

/*
    wipe bit from all the internal bitboards
*/
void Chessboard::WipePiece(int Square) 
{
/* 
    DelBit(&WhiteBlackBitBoard, Square);  

    for (int WhiteBitboardIterator=0; WhiteBitboardIterator < 6; WhiteBitboardIterator++) 
    {
        DelBit(WhiteBitboardArry[WhiteBitboardIterator], Square);
    }

    for (int BlackBitboardIterator=0; BlackBitboardIterator < 6; BlackBitboardIterator++)
    {
       DelBit(BlackBitboardArry[BlackBitboardIterator], Square); 
    }

    for (int SideBoardIterator=0; SideBoardIterator < 2; SideBoardIterator++) 
    {
        DelBit(SideBitboardArray[SideBoardIterator], Square);
    }
*/
    int PieceType = GetPieceType(Square);

    DelBit(&WhiteBlackBitBoard, Square);
    DelBit(PieceTypeBitboardArray[PieceType], Square);

    int Side;

    if (PieceType <= 5) 
    {
        Side = black;
    }
    else 
    {
        Side = white;
    }

    DelBit(SideBitboardArray[Side], Square);
}

/*
    place a piticular piece on a square
*/
void Chessboard::PutPiece(int Square, int PieceType) 
{
    AddBit(&WhiteBlackBitBoard, Square);
    AddBit(PieceTypeBitboardArray[PieceType], Square);
    
    int Side;

    if (PieceType < 6) 
    {
        Side = black;
    }
    else 
    {
        Side = white;
    }

    AddBit(SideBitboardArray[Side], Square);

}

void Chessboard::ClearBoard() 
{
    WhiteBlackBitBoard = 0ULL;
    BlackRookBitBoard = 0ULL;
    BlackPawnBitBoard = 0ULL;
    BlackBishopBitBoard = 0ULL;
    BlackKingBitBoard = 0ULL;
    BlackQueenBitBoard = 0ULL;
    BlackKnightBitBoard = 0ULL;
    BlackRookBitBoard = 0ULL;
    WhitePawnBitBoard = 0ULL;
    WhiteBishopBitBoard = 0ULL;
    WhiteKingBitBoard = 0ULL;
    WhiteQueenBitBoard = 0ULL;
    WhiteKnightBitBoard = 0ULL;
    WhiteRookBitBoard = 0ULL;
    WhiteBitBoard = 0ULL;
}

int Chessboard::DoMove(Move MoveToDo) 
{

    //std::cout << " Side To Move: " << SideToMove << "\n";

    SideToMove = !SideToMove;

    //std::cout << "Side to move: " << SideToMove << "\n";

    Moves.push_back(MoveToDo);

    int OriginBitstatus = GetBit(&WhiteBlackBitBoard, MoveToDo.Origin);
    
    //std::cout << OriginBitstatus << "\n";

    if (OriginBitstatus == 1) {
        WipePiece(MoveToDo.Origin);    
    }

    int DestinationBitstatus = GetBit(&WhiteBlackBitBoard, MoveToDo.Destination);

    //std::cout << DestinationBitstatus << "\n";

    if (DestinationBitstatus == 1) {
        WipePiece(MoveToDo.Destination);
    }
    
    PutPiece(MoveToDo.Destination, MoveToDo.PieceType);

    return 1;
}

int Chessboard::UndoLastMove() {

    SideToMove = !SideToMove;

    Move MoveForRemoval = Moves[Moves.size()-1];

    if (GetBit(&WhiteBlackBitBoard, MoveForRemoval.Origin)) {
        WipePiece(MoveForRemoval.Origin);
    }

    if (GetBit(&WhiteBlackBitBoard, MoveForRemoval.Destination) == 1) {
        WipePiece(MoveForRemoval.Destination);
    }

    PutPiece(MoveForRemoval.Origin, MoveForRemoval.PieceType);

    Moves.pop_back();

    return 1;

}
