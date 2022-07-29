/*
    the centeral class of mojave engine a chessbaord class is in charge of:

    ~ storing, managing, tracking the internel state of the bitboards
    ~ generating moves using those bitboards and move data calculated in move.cpp
    ~ evaluating the board position mapping a score to a position 
    ~ searching the available moves using generation functions and evaluation functions to choose an optimal move

    this class is the largest part of the program so the implementation is divised between several files


*/


#include "Chessboard.hpp"
#include "Bitboard.hpp"
#include "BoardConcepts.hpp"
#include <cstdlib>
#include <ctime>

// algorithm that takes the FEN
// see https://en.wikipedia.org/wiki/Forsyth%E2%80%93Edwards_Notation
void Chessboard::ParseFEN(std::string FEN) {

    char CharArrayOfFenString[FEN.length() + 1];

    strcpy(CharArrayOfFenString, FEN.c_str());

    ClearBoard();

    int CurrentSquare = 0;

    for (int FENPosition = 0; FENPosition < FEN.length(); FENPosition++) {
        if (CurrentSquare != 64) {

            #ifdef DEBUG
                std::cout << "\nSwitching for: " << CharArrayOfFenString[FENPosition] << "\n\n";
            #endif

            switch (CharArrayOfFenString[FENPosition]) {
               case 'r':
                    #ifdef DEBUG
                        std::cout << "black rook found on square: " << CurrentSquare << "\n";
                    #endif
    
                   PutPiece(CurrentSquare, BlackRook);

                   CurrentSquare++;

                   break;
               case 'n':
                   #ifdef DEBUG
                        std::cout << "Black Knight found on square: " << CurrentSquare << "\n";
                   #endif
                   
                   PutPiece(CurrentSquare, BlackKnight);

                   CurrentSquare++;

                   break;
               case 'b':
                    #ifdef DEBUG
                        std::cout << "black Bishop found on square: " << CurrentSquare << "\n";
                    #endif

                    PutPiece(CurrentSquare, BlackBishop);

                   CurrentSquare++;

                   break;
               case 'q':

                    #ifdef DEBUG
                        std::cout << "Black Knight queen on square: " << CurrentSquare << "\n";
                    #endif

                   PutPiece(CurrentSquare, BlackQueen);

                   CurrentSquare++;

                   break;
               case 'k':

                    #ifdef DEBUG
                        std::cout << "black rook found on square: " << CurrentSquare << "\n";
                    #endif

                   PutPiece(CurrentSquare, BlackKing);

                   CurrentSquare++;

                   break;
               case 'p':

                   //std::cout << "Black pawn found on square: " << CurrentSquare << "\n";

                   PutPiece(CurrentSquare, BlackPawn);

                   CurrentSquare++;

                   break;
               case 'R':

                   //std::cout << "white rook found on square: " << CurrentSquare << "\n";

                   PutPiece(CurrentSquare, WhiteRook);

                   CurrentSquare++;

                   break;
               case 'N':

                   //std::cout << "White Knight found on square: " << CurrentSquare << "\n";

                   PutPiece(CurrentSquare, WhiteKnight);

                   CurrentSquare++;

                   break;
               case 'B':

                   //std::cout << "White Bishop found on square: " << CurrentSquare << "\n";

                   PutPiece(CurrentSquare, WhiteBishop);

                   CurrentSquare++;

                   break;
               case 'Q':

                   //std::cout << "White Queen on square: " << CurrentSquare << "\n";

                   PutPiece(CurrentSquare, WhiteQueen);

                   CurrentSquare++;

                   break;
               case 'K':
                   //std::cout << "White King found on square: " << CurrentSquare << "\n";
                   PutPiece(CurrentSquare, WhiteKing);
                   CurrentSquare++;
                   break;
               case 'P':
                   //std::cout << "White pawn found on square: " << CurrentSquare << "\n";
                   PutPiece(CurrentSquare, WhitePawn);
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
    #ifdef DEBUG    
        std::cout << "\n" << "Parsing: " << FEN << " Complete" << "\n\n";
    #endif
}

/*
    Create and return a move struct from an algerbrraic notation eg e2e4

    To make this possible it MUST be done here with reference to a piece positions 
*/
Move Chessboard::CreateMoveFromAlgerbraicNotation(std::string AlgerbraicNotation) 
{
    std::string OriginAlgerbraicNotation = AlgerbraicNotation.substr(0, 2);
    std::string DestinationAlgerbraicNotation = AlgerbraicNotation.substr(2, 4);

    int Origin;
    int Destination;
    
    int PieceType;
    int Side;

    for (int SquareMappingArrayIterator=0; SquareMappingArrayIterator < 64; SquareMappingArrayIterator++) 
    {
        if (SqaureMappingArray[SquareMappingArrayIterator] == OriginAlgerbraicNotation) 
        {
            Origin = SquareMappingArrayIterator;
    
            //std::cout << Origin << "\n";
        }

        if (SqaureMappingArray[SquareMappingArrayIterator] == DestinationAlgerbraicNotation)
        {
            Destination = SquareMappingArrayIterator;
        
            //std::cout << Destination << "\n";
        }
    }

    for (int PieceTypeBitboardArrayIterator=0; PieceTypeBitboardArrayIterator < 12; PieceTypeBitboardArrayIterator++) 
    {
        int Bitstatus = GetBit(PieceTypeBitboardArray[PieceTypeBitboardArrayIterator], Origin);

        if (Bitstatus == 1) 
        {
            PieceType = PieceTypeBitboardArrayIterator; 
        }
    }

    if (PieceType < 5) 
    {
        Side = black;
    } 
    else 
    {
        Side = white;
    }

    Move FinalMove(Origin, Destination, Side, PieceType);

    return FinalMove;
}

int Chessboard::DoMove(Move MoveToDo) 
{

    //std::cout << " Side To Move: " << SideToMove << "\n";

    SideToMove = !SideToMove;

    //std::cout << "Side to move: " << SideToMove << "\n";

    Moves.push_back(MoveToDo);

    int OriginBitstatus = GetBit(&WhiteBlackBitBoard, MoveToDo.Origin);

    if (OriginBitstatus == 1) {
        WipePiece(MoveToDo.Origin);    
    }

    int DestinationBitstatus = GetBit(&WhiteBlackBitBoard, MoveToDo.Destination);

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

        } 
        else 
        {

            FuncIndex += (BoardIterator - 6);
            PieceColor = white;

        }

        if (PieceColor == side) 
        {
            while (*PieceTypeBitboardArray[BoardIterator] != 0) 
            {

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

        } 
        else 
        {

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

void Chessboard::ShowMove(Move MoveToShow) 
{
    // these two arrays are mapped;

    // squares that will have arrows on them to show the move
    int SquaresThatWillHaveArrows[8];
    
    // the unicode arrow that will be printed
    int TypeOfArrowOnSquare[8];

    if (MoveToShow.PieceType == BlackPawn) 
    {
        if (MoveToShow.Destination - MoveToShow.Origin) 
        {

        }
    }

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
                 std::cout << PieceAsciiSymbols[MoveToShow.PieceType] << " ";
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

    ZobristInit();
}

Chessboard::Chessboard() 
{
    ZobristInit();
}
