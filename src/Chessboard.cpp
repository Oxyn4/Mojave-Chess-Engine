
#include "BoardConcepts.h"
#include "Bitboard.h"
#include "Chessboard.h"
#include "Moves.h"

#include <cstring>
#include <iostream>
#include <chrono>
#include <vector>
#include <thread>
#include <stdio.h>

uint64_t Chessboard::ClassicalGenerateRookMoves(int square, int side) {
  //    std::cout << "Getting all rook moves for square: " << square << "\n";
  //  auto FuncStartPoint = std::chrono::high_resolution_clock::now();
    
    uint64_t NorthBitboard;
    uint64_t EastBitboard;
    uint64_t WestBitboard;
	uint64_t SouthBitboard;
    
    // ! north

    // a northern ray cast from bit position to boards edge

    uint64_t NorthBlockerMask = RaysArray[square][North];
    
    // bits that block the ray both friendly and enemy

    uint64_t NorthBlockers = NorthBlockerMask & WhiteBlackBitBoard;
    
    // if there is no blockers then just use the ray
    if (NorthBlockers != 0) {
        // get the fist blockers index
        int Northlsb = BitscanMSB(&NorthBlockers);
        uint64_t NorthRayBitboard = NorthBlockerMask & ~RaysArray[Northlsb][North];
        
        NorthBitboard = NorthRayBitboard & ~*SideBitboardArray[side];
    } else {
        NorthBitboard = NorthBlockerMask & ~*SideBitboardArray[side];
    }
    
    //! east
    uint64_t EastBlockerMask = RaysArray[square][East];
    uint64_t EastBlockers = EastBlockerMask & WhiteBlackBitBoard;
    if (EastBlockers != 0) {
        int Eastlsb = BitScanLSB(&EastBlockers);
        uint64_t EastRayBitboard = EastBlockerMask & ~RaysArray[Eastlsb][East];
        EastBitboard = EastRayBitboard & ~*SideBitboardArray[side];
    } else {
        EastBitboard = EastBlockerMask & ~*SideBitboardArray[side];
    }
    
    // ! south
    uint64_t SouthBlockerMask = RaysArray[square][South];
    uint64_t SouthBlockers = SouthBlockerMask & WhiteBlackBitBoard;
    if (SouthBlockers != 0) {
        int Southlsb = BitScanLSB(&SouthBlockers);
        uint64_t SouthRayBitboard = SouthBlockerMask & ~RaysArray[Southlsb][South];
        SouthBitboard = SouthRayBitboard & ~*SideBitboardArray[side];
    } else {
        SouthBitboard = SouthBlockerMask & ~*SideBitboardArray[side];
    }
    
    // ! west
    uint64_t WestBlockerMask = RaysArray[square][West];
    uint64_t WestBlockers = WestBlockerMask & WhiteBlackBitBoard;
    if (WestBlockers != 0) {
        int Westlsb = BitScanLSB(&WestBlockers);
        uint64_t WestRayBitboard = WestBlockerMask & ~RaysArray[Westlsb][West];
        WestBitboard = WestRayBitboard & ~*SideBitboardArray[side];
    } else {
        WestBitboard = WestBlockerMask & ~*SideBitboardArray[side];
    }
    uint64_t FinalBitboard = SouthBitboard | WestBitboard | EastBitboard | NorthBitboard;
    //auto StoppingPoint = std::chrono::high_resolution_clock::now();
    //auto Duration = std::chrono::duration_cast<std::chrono::microseconds>(StoppingPoint - FuncStartPoint);
    //std::cout << "Finished getting moves for a Rook on square: " << square << " in: " << Duration.count()  << " microseconds"  << "\n\n";
    //PrintBitboard(FinalBitboard); 
    return FinalBitboard;
}

uint64_t Chessboard::ClassicalGenerateBishopMoves(int Square, int side) {
    //std::cout << "Getting all moves for a bishop on square: " << Square << "\n";
    //auto FuncStartPoint = std::chrono::high_resolution_clock::now();
    
    uint64_t NorthwestBitboard;
    uint64_t SouthwestBitboard;
    uint64_t NortheastBitboard;
    uint64_t SoutheastBitboard;
    
    // ! Northwest
    uint64_t NorthwestBlockerMask = RaysArray[Square][Northwest];
    uint64_t NorthwestBlockers = NorthwestBlockerMask & WhiteBlackBitBoard;
    if (NorthwestBlockers != 0) {
        int Northwestlsb = BitScanLSB(&NorthwestBlockers);
        uint64_t NorthwestRayBitboard = NorthwestBlockerMask & ~RaysArray[Northwestlsb][Northwest];
        NorthwestBitboard = NorthwestRayBitboard & ~*SideBitboardArray[side];
    } else {
        NorthwestBitboard = NorthwestBlockerMask & ~*SideBitboardArray[side];
    }
    
    // ! northeast
    uint64_t NortheastBlockerMask = RaysArray[Square][Northeast];
    uint64_t NortheastBlockers = NortheastBlockerMask & WhiteBlackBitBoard;
    if (NortheastBlockers != 0) {
        int Northeastlsb = BitScanLSB(&NortheastBlockers);
        uint64_t NortheastRayBitboard = NortheastBlockerMask & ~RaysArray[Northeastlsb][Northeast];
        NortheastBitboard = NortheastRayBitboard & ~*SideBitboardArray[side];
    } else {
        NortheastBitboard = NortheastBlockerMask & ~*SideBitboardArray[side];
    }
    // ! Southeast
    uint64_t SoutheastBlockerMask = RaysArray[Square][Southeast];
    uint64_t SoutheastBlockers = SoutheastBlockerMask & WhiteBlackBitBoard;
    if (SoutheastBlockers != 0) {
        int Southeastmsb = BitscanMSB(&SoutheastBlockers);
        uint64_t SoutheastRayBitboard = SoutheastBlockerMask & ~RaysArray[Southeastmsb][Southeast];
        SoutheastBitboard = SoutheastRayBitboard & ~*SideBitboardArray[side];
    } else {
        SoutheastBitboard = SoutheastBlockerMask & ~*SideBitboardArray[side];
    }
    // ! southwest
    uint64_t SouthwestBlockerMask = RaysArray[Square][Southwest];
    uint64_t SouthwestBlockers = SouthwestBlockerMask & WhiteBlackBitBoard;
    if (SoutheastBlockers != 0) {
        int Southwestmsb = BitscanMSB(&SouthwestBlockers);
        uint64_t SouthwestRayBitboard = SouthwestBlockerMask & ~RaysArray[Southwestmsb][Southwest];
        SouthwestBitboard = SouthwestRayBitboard & ~*SideBitboardArray[side];
    } else {
        SouthwestBitboard = SouthwestBlockerMask & ~*SideBitboardArray[side];
    }
    uint64_t FinalBitboard = SoutheastBitboard | SouthwestBitboard | NortheastBitboard | NorthwestBitboard;
    //PrintBitboard(FinalBitboard); 
    //PrintBitboard(~RaysArray[Southeastmsb][Southeast]);
    //auto StoppingPoint = std::chrono::high_resolution_clock::now();
    //auto Duration = std::chrono::duration_cast<std::chrono::microseconds>(StoppingPoint - FuncStartPoint);
    //std::cout << "Finished getting moves for a Bishop on square: " << Square << " in: " << Duration.count()  << " microseconds"  << "\n\n";
    return FinalBitboard;
}

uint64_t Chessboard::ClassicalGenerateQueenMoves(int square, int side) {
    //std::cout << "Getting all moves for a queen on square: " << square << "\n\n";
    //auto FuncStartPoint = std::chrono::high_resolution_clock::now();
    uint64_t Rookpattern = ClassicalGenerateRookMoves(square, side);
    uint64_t Bishoppattern = ClassicalGenerateBishopMoves(square, side);
    uint64_t Queenpattern = Bishoppattern | Rookpattern;
    //auto StoppingPoint = std::chrono::high_resolution_clock::now();
    //auto Duration = std::chrono::duration_cast<std::chrono::microseconds>(StoppingPoint - FuncStartPoint);
    //std::cout << "Finished getting moves for a Queen on square: " << square << " in: " << Duration.count()  << " microseconds"  << "\n\n";
    return Queenpattern;
}


uint64_t Chessboard::GetKingMoves(int square, int side) {
    uint64_t KingMask = KingMoves[square];
    uint64_t KingBitboard = KingMask & ~*SideBitboardArray[side];
    

    return KingBitboard;
}

uint64_t Chessboard::GetKnightMoves(int square, int side) {

    //std::cout << "Getting Knight moves\n";

    uint64_t PotentialKnightMoves = KnightMoves[square];

    uint64_t FinalKnightMoves = PotentialKnightMoves & ~*SideBitboardArray[side];

    return FinalKnightMoves;
}

uint64_t Chessboard::GetPawnMoves(int square, int side) {
    uint64_t PawnMoveMask = PawnMoves[side][square];
    //PrintBitboard(PawnMoveMask);
    uint64_t PawnAttackMask = PawnAttacks[side][square];
    //PrintBitboard(PawnAttackMask);
    uint64_t PawnAttackBitboard = PawnAttackMask & (~WhiteBlackBitBoard ^ ~*SideBitboardArray[side]);
    //PrintBitboard(PawnAttackBitboard);
    uint64_t PawnMoveBitboard = PawnMoveMask & ~WhiteBlackBitBoard;
    //PrintBitboard(PawnMoveBitboard);

    uint64_t PawnBitboard = PawnMoveBitboard | PawnAttackBitboard;
    //PrintBitboard(PawnBitboard);
    
    return PawnBitboard;
}


// algorithm that takes the FEN
// see https://en.wikipedia.org/wiki/Forsyth%E2%80%93Edwards_Notation
void Chessboard::ParseFEN(std::string FEN) {

    char CharArrayOfFenString[FEN.length() + 1];

    strcpy(CharArrayOfFenString, FEN.c_str());

    // clear bitboards

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
    BlackBitBoard = 0ULL;

    int CurrentSquare = 0;

    for (int FENPosition = 0; FENPosition < FEN.length(); FENPosition++) {
        if (CurrentSquare != 64) {

            //std::cout << "\nSwitching for: " << CharArrayOfFenString[FENPosition] << "\n\n";

            switch (CharArrayOfFenString[FENPosition]) {
               case 'r':

                   //std::cout << "black rook found on square: " << CurrentSquare << "\n";

                   WhiteBlackBitBoard |= (1ULL << CurrentSquare) ? WhiteBlackBitBoard ^= (1ULL << CurrentSquare) : 0;
                   BlackRookBitBoard |= (1ULL << CurrentSquare) ? BlackRookBitBoard ^= (1ULL << CurrentSquare) : 0;
                   BlackBitBoard |= (1ULL << CurrentSquare) ? BlackBitBoard ^= (1ULL << CurrentSquare) : 0;

                   CurrentSquare++;

                   break;
               case 'n':

                   //std::cout << "Black Knight found on square: " << CurrentSquare << "\n";

                   WhiteBlackBitBoard |= (1ULL << CurrentSquare) ? WhiteBlackBitBoard ^= (1ULL << CurrentSquare) : 0;
                   BlackKnightBitBoard |= (1ULL << CurrentSquare) ? BlackKnightBitBoard ^= (1ULL << CurrentSquare) : 0;
                   BlackBitBoard |= (1ULL << CurrentSquare) ? BlackBitBoard ^= (1ULL << CurrentSquare) : 0;

                   CurrentSquare++;

                   break;
               case 'b':

                   //std::cout << "black Bishop found on square: " << CurrentSquare << "\n";

                   WhiteBlackBitBoard |= (1ULL << CurrentSquare) ? WhiteBlackBitBoard ^= (1ULL << CurrentSquare) : 0;
                   BlackBishopBitBoard |= (1ULL << CurrentSquare) ? BlackBishopBitBoard ^= (1ULL << CurrentSquare) : 0;
                   BlackBitBoard |= (1ULL << CurrentSquare) ? BlackBitBoard ^= (1ULL << CurrentSquare) : 0;

                   CurrentSquare++;

                   break;
               case 'q':

                   //std::cout << "Black Knight queen on square: " << CurrentSquare << "\n";

                   WhiteBlackBitBoard |= (1ULL << CurrentSquare) ? WhiteBlackBitBoard ^= (1ULL << CurrentSquare) : 0;
                   BlackQueenBitBoard |= (1ULL << CurrentSquare) ? BlackQueenBitBoard ^= (1ULL << CurrentSquare) : 0;
                   BlackBitBoard |= (1ULL << CurrentSquare) ? BlackBitBoard ^= (1ULL << CurrentSquare) : 0;

                   CurrentSquare++;

                   break;
               case 'k':

                   //std::cout << "black rook found on square: " << CurrentSquare << "\n";

                   WhiteBlackBitBoard |= (1ULL << CurrentSquare) ? WhiteBlackBitBoard ^= (1ULL << CurrentSquare) : 0;
                   BlackKingBitBoard |= (1ULL << CurrentSquare) ? BlackKingBitBoard ^= (1ULL << CurrentSquare) : 0;
                   BlackBitBoard |= (1ULL << CurrentSquare) ? BlackBitBoard ^= (1ULL << CurrentSquare) : 0;

                   CurrentSquare++;

                   break;
               case 'p':

                   //std::cout << "Black pawn found on square: " << CurrentSquare << "\n";

                   WhiteBlackBitBoard |= (1ULL << CurrentSquare) ? WhiteBlackBitBoard ^= (1ULL << CurrentSquare) : 0;
                   BlackPawnBitBoard |= (1ULL << CurrentSquare) ? BlackPawnBitBoard ^= (1ULL << CurrentSquare) : 0;
                   BlackBitBoard |= (1ULL << CurrentSquare) ? BlackBitBoard ^= (1ULL << CurrentSquare) : 0;

                   CurrentSquare++;

                   break;
               case 'R':

                   //std::cout << "white rook found on square: " << CurrentSquare << "\n";

                   WhiteBlackBitBoard |= (1ULL << CurrentSquare) ? WhiteBlackBitBoard ^= (1ULL << CurrentSquare) : 0;
                   WhiteRookBitBoard |= (1ULL << CurrentSquare) ? WhiteRookBitBoard ^= (1ULL << CurrentSquare) : 0;
                   WhiteBitBoard |= (1ULL << CurrentSquare) ? WhiteBitBoard ^= (1ULL << CurrentSquare) : 0;

                   CurrentSquare++;

                   break;
               case 'N':

                   //std::cout << "White Knight found on square: " << CurrentSquare << "\n";

                   WhiteBlackBitBoard |= (1ULL << CurrentSquare) ? WhiteBlackBitBoard ^= (1ULL << CurrentSquare) : 0;
                   WhiteKnightBitBoard |= (1ULL << CurrentSquare) ? WhiteKnightBitBoard ^= (1ULL << CurrentSquare) : 0;
                   WhiteBitBoard |= (1ULL << CurrentSquare) ? WhiteBitBoard ^= (1ULL << CurrentSquare) : 0;

                   CurrentSquare++;

                   break;
               case 'B':

                   //std::cout << "White Bishop found on square: " << CurrentSquare << "\n";

                   WhiteBlackBitBoard |= (1ULL << CurrentSquare) ? WhiteBlackBitBoard ^= (1ULL << CurrentSquare) : 0;
                   WhiteBishopBitBoard |= (1ULL << CurrentSquare) ? WhiteBishopBitBoard ^= (1ULL << CurrentSquare) : 0;
                   WhiteBitBoard |= (1ULL << CurrentSquare) ? WhiteBitBoard ^= (1ULL << CurrentSquare) : 0;

                   CurrentSquare++;

                   break;
               case 'Q':

                   //std::cout << "White Queen on square: " << CurrentSquare << "\n";

                   WhiteBlackBitBoard |= (1ULL << CurrentSquare) ? WhiteBlackBitBoard ^= (1ULL << CurrentSquare) : 0;
                   WhiteQueenBitBoard |= (1ULL << CurrentSquare) ? WhiteQueenBitBoard ^= (1ULL << CurrentSquare) : 0;
                   WhiteBitBoard |= (1ULL << CurrentSquare) ? WhiteBitBoard ^= (1ULL << CurrentSquare) : 0;

                   CurrentSquare++;

                   break;
               case 'K':

                   //std::cout << "White King found on square: " << CurrentSquare << "\n";

                   WhiteBlackBitBoard |= (1ULL << CurrentSquare) ? WhiteBlackBitBoard ^= (1ULL << CurrentSquare) : 0;
                   WhiteKingBitBoard |= (1ULL << CurrentSquare) ? WhiteKingBitBoard ^= (1ULL << CurrentSquare) : 0;
                   WhiteBitBoard |= (1ULL << CurrentSquare) ? WhiteBitBoard ^= (1ULL << CurrentSquare) : 0;

                   CurrentSquare++;

                   break;
               case 'P':

                   //std::cout << "White pawn found on square: " << CurrentSquare << "\n";

                   WhiteBlackBitBoard |= (1ULL << CurrentSquare) ? WhiteBlackBitBoard ^= (1ULL << CurrentSquare) : 0;
                   WhitePawnBitBoard |= (1ULL << CurrentSquare) ? WhitePawnBitBoard ^= (1ULL << CurrentSquare) : 0;
                   WhiteBitBoard |= (1ULL << CurrentSquare) ? WhiteBitBoard ^= (1ULL << CurrentSquare) : 0;

                   CurrentSquare++;

                   break;
               case '1':
                   //std::cout << "Number 1 found" << "\n";

                   CurrentSquare += 1;

                   continue;
               case '2':
                   //std::cout << "Number 2 found" << "\n";

                   CurrentSquare += 2;

                    break;
               case '3':
                   //std::cout << "Number 3 found" << "\n";

                   CurrentSquare += 3;

                    break;
               case '4':
                   //std::cout << "Number 4 found" << "\n";

                   CurrentSquare += 4;

                    break;
               case '5':
                   //std::cout << "Number 5 found" << "\n";

                   CurrentSquare += 5;

                    break;
               case '6':
                   //std::cout << "Number 6 found" << "\n";

                   CurrentSquare += 6;

                    break;
               case '7':
                   //std::cout << "Number 7 found" << "\n";

                   CurrentSquare += 7;

                    break;
               case '8':
                   //std::cout << "Number 8 found" << "\n";

                   CurrentSquare += 8;

                   break;     
            }
        }
    }
    //std::cout << "\n" << "Parsing: " << FEN << " Complete" << "\n\n";
}

int Chessboard::DoMove(Move MoveToDo) 
{

    //std::cout << " Side To Move: " << SideToMove << "\n";

    SideToMove = !SideToMove;

    //std::cout << "Side to move: " << SideToMove << "\n";

    Moves.push_back(MoveToDo);

    int OriginBitstatus = GetBit(&WhiteBlackBitBoard, MoveToDo.Origin);

    if (OriginBitstatus == 1) {
        DelBit(PieceTypeBitboardArray[MoveToDo.PieceType], MoveToDo.Origin);
        DelBit(&WhiteBlackBitBoard, MoveToDo.Origin);
        DelBit(SideBitboardArray[MoveToDo.Side], MoveToDo.Origin);
    }

    int DestinationBitstatus = GetBit(&WhiteBlackBitBoard, MoveToDo.Destination);

    if (DestinationBitstatus == 1) {
        DelBit(PieceTypeBitboardArray[MoveToDo.PieceType], MoveToDo.Destination);
        DelBit(&WhiteBlackBitBoard, MoveToDo.Destination);
        DelBit(SideBitboardArray[MoveToDo.Side], MoveToDo.Destination);
    }

    AddBit(PieceTypeBitboardArray[MoveToDo.PieceType], MoveToDo.Destination);
    AddBit(&WhiteBlackBitBoard, MoveToDo.Destination);
    AddBit(SideBitboardArray[MoveToDo.Side], MoveToDo.Destination);

    return 1;
}

int Chessboard::UndoLastMove(Move MoveForRemoval) {

    SideToMove = !SideToMove;

    Moves.pop_back();

    if (GetBit(&WhiteBlackBitBoard, MoveForRemoval.Origin)) {
        DelBit(PieceTypeBitboardArray[MoveForRemoval.PieceType], MoveForRemoval.Origin);
        DelBit(&WhiteBlackBitBoard, MoveForRemoval.Origin);
        DelBit(SideBitboardArray[MoveForRemoval.Side], MoveForRemoval.Origin);
    }

    if (GetBit(&WhiteBlackBitBoard, MoveForRemoval.Destination) == 1) {
        DelBit(PieceTypeBitboardArray[MoveForRemoval.PieceType], MoveForRemoval.Destination);
        DelBit(&WhiteBlackBitBoard, MoveForRemoval.Destination);
        DelBit(SideBitboardArray[MoveForRemoval.Side], MoveForRemoval.Destination);
    }

    AddBit(PieceTypeBitboardArray[MoveForRemoval.PieceType], MoveForRemoval.Origin);
    AddBit(&WhiteBlackBitBoard, MoveForRemoval.Origin);
    AddBit(SideBitboardArray[MoveForRemoval.Side], MoveForRemoval.Origin);


    return 1;

}

std::vector<Move> Chessboard::GetAllSidesMoves(int side)
{
    //timing 


  //  std::cout << "\nGetting all legal moves for side: " << side << "\n";

    //auto FuncStartPoint = std::chrono::high_resolution_clock::now();

    //vector conatins Move Structs which represent legal moves

    std::vector<Move> LegalMoveVector;

    for (int BoardIterator = 0; BoardIterator < 12; BoardIterator++)
    {        
        // work out the index for the function 
 
        int FuncIndex = 0;
        int PieceColor = 0;

        if (BoardIterator <= 5)
        {
            
            FuncIndex += BoardIterator;
            PieceColor = black;

        } else {

            FuncIndex += (BoardIterator - 6);
            PieceColor = white;

        }

        if (PieceColor == side) {
            while (*PieceTypeBitboardArray[BoardIterator] != 0) {

                int BoardLSB = BitScanLSB(PieceTypeBitboardArray[BoardIterator]);

                //PrintBitboard(PieceTypeBitboardArray[BoardIterator]);

                //std::cout << BoardLSB << "\n";

                uint64_t MovesBitboard = (this->*MoveCalculatingFunctions[FuncIndex])(BoardLSB, PieceColor);

                while (MovesBitboard != 0) {

                    int MovesBitboardLSB = BitScanLSB(&MovesBitboard);

                    Move NewMove(BoardLSB, MovesBitboardLSB, PieceColor, FuncIndex);

                    LegalMoveVector.push_back(NewMove);

                    MovesBitboard &= MovesBitboard - 1;   
                }

                *PieceTypeBitboardArray[BoardIterator] &= *PieceTypeBitboardArray[BoardIterator] - 1;    
            }        
        }
    }
    
/*    std::cout << LegalMoveVector.size() << " Amount of moves available in this position for this side" << "\n";

    auto StoppingPoint = std::chrono::high_resolution_clock::now();

    auto Duration = std::chrono::duration_cast<std::chrono::microseconds>(StoppingPoint - FuncStartPoint);

    std::cout << "Finished Calculating Legal moves in " << Duration.count()  << " microseconds"  << "\n\n";
*/
    

    return LegalMoveVector;
}

std::vector<Move> Chessboard::GetAllMoves()
{
    //timing 


    std::cout << "\nGetting all legal moves" << "\n";

    auto FuncStartPoint = std::chrono::high_resolution_clock::now();

    //vector conatins Move Structs which represent legal moves

    std::vector<Move> LegalMoveVector;

    for (int BoardIterator = 0; BoardIterator < 12; BoardIterator++)
    {        
        // work out the index for the function 
 
        int FuncIndex = 0;
        int PieceColor = 0;

        if (BoardIterator <= 5)
        {
            
            FuncIndex += BoardIterator;
            PieceColor = black;

        } else {

            FuncIndex += (BoardIterator - 6);
            PieceColor = white;

        }

        
        while (*PieceTypeBitboardArray[BoardIterator] != 0) {

            int BoardLSB = BitScanLSB(PieceTypeBitboardArray[BoardIterator]);

            //PrintBitboard(PieceTypeBitboardArray[BoardIterator]);

            //std::cout << BoardLSB << "\n";

            uint64_t MovesBitboard = (this->*MoveCalculatingFunctions[FuncIndex])(BoardLSB, PieceColor);

            while (MovesBitboard != 0) {

                int MovesBitboardLSB = BitScanLSB(&MovesBitboard);

                Move NewMove(BoardLSB, MovesBitboardLSB, PieceColor, FuncIndex);

                LegalMoveVector.push_back(NewMove);

                MovesBitboard &= MovesBitboard - 1;   
            }

            *PieceTypeBitboardArray[BoardIterator] &= *PieceTypeBitboardArray[BoardIterator] - 1;    
        }        
    }
    
    
    
   
    auto StoppingPoint = std::chrono::high_resolution_clock::now();

    auto Duration = std::chrono::duration_cast<std::chrono::microseconds>(StoppingPoint - FuncStartPoint);

    std::cout << "Finished Calculating Legal moves in " << Duration.count()  << " microseconds"  << "\n\n";

    return LegalMoveVector;
}

void Chessboard::PrintChesssboard()
{
    for (int RankIterator=0; RankIterator < 8; RankIterator++) 
    {
        for (int FileIterator=0; FileIterator < 8; FileIterator++) 
        {
            int Sqaure = RankIterator * 8 + FileIterator;

            int OneOrZero = ((WhiteBlackBitBoard & (1ULL << Sqaure)) ? 1 : 0);

            if (FileIterator == 0) 
            {
                std::cout << 8 - RankIterator << " | "; 
            }

            if (OneOrZero == 1) 
            {
                for (int PieceTypeBitboardArrayIterator=0; PieceTypeBitboardArrayIterator < 12; PieceTypeBitboardArrayIterator++) 
                {
  
                    int IsPieceThisType = ((*PieceTypeBitboardArray[PieceTypeBitboardArrayIterator] & (1ULL << Sqaure)) ? 1 : 0);
                
                    if (IsPieceThisType == 1) 
                    {
                        std::cout << PieceAsciiSymbols[PieceTypeBitboardArrayIterator] << " ";
                    } 
                }
            }
            else 
            {
                std::cout << ". ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "    ---------------" << "\n";
    std::cout << "    a b c d e f g h" << "\n";
}

// constructor for this class 
// sets up the board by parsing fen given during object creation
Chessboard::Chessboard(std::string FEN) 
{

    ParseFEN(FEN);

}
