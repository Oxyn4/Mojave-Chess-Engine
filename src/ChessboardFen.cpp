
#include "BoardConcepts.hpp"
#include "Chessboard.hpp"
/*
// algorithm that takes the FEN
// see https://en.wikipedia.org/wiki/Forsyth%E2%80%93Edwards_Notation
void Chessboard::ParseFEN(std::string FEN) {

    char CharArrayOfFenString[FEN.length() + 1];

    strcpy(CharArrayOfFenString, FEN.c_str());

    ClearBoard();

    int CurrentSquare = 0;

    for (int FENPosition = 0; FENPosition < FEN.length(); FENPosition++) 
    {
        if (CurrentSquare != 64) 
        {

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
*/

void Chessboard::ParseFEN(std::string FEN) 
{

        std::vector<std::string> FENTokenVector;

        std::istringstream FENStringStream(FEN);

        std::string Token;

        while (FENStringStream >> Token)
        {
                FENTokenVector.push_back(Token);
        }

        int CurrentSquare = 0;

        std::string PiecePositions = FENTokenVector[0];

        for (int PiecePositionsIterator=0; PiecePositionsIterator < FENTokenVector[0].length(); PiecePositionsIterator++) 
        {
               if (PiecePositions[PiecePositionsIterator] == 'p') 
               {
                       PutPiece(CurrentSquare, BlackPawn);
                        CurrentSquare++;
               }
               else if (PiecePositions[PiecePositionsIterator] == 'b') 
               {
                       PutPiece(CurrentSquare, BlackBishop);
                        CurrentSquare++;

               }
               else if (PiecePositions[PiecePositionsIterator] == 'k') 
               {
                       PutPiece(CurrentSquare, BlackKing);
                        CurrentSquare++;

               }
               else if (PiecePositions[PiecePositionsIterator] == 'q') 
               {
                       PutPiece(CurrentSquare, BlackQueen);
                        CurrentSquare++;

               }
               else if (PiecePositions[PiecePositionsIterator] == 'n') 
               {
                       PutPiece(CurrentSquare, BlackKnight);
                        CurrentSquare++;

               }
               else if (PiecePositions[PiecePositionsIterator] == 'r') 
               {
                        PutPiece(CurrentSquare, BlackRook);
                        CurrentSquare++;

               }
               else if (PiecePositions[PiecePositionsIterator] == 'P') 
               {
                        PutPiece(CurrentSquare, WhitePawn);
                        CurrentSquare++;

               }
               else if (PiecePositions[PiecePositionsIterator] == 'B') 
               {
                        PutPiece(CurrentSquare, WhiteBishop);
                        CurrentSquare++;

               }
               else if (PiecePositions[PiecePositionsIterator] == 'K') 
               {
                        PutPiece(CurrentSquare, WhiteKing);
                        CurrentSquare++;

               }
               else if (PiecePositions[PiecePositionsIterator] == 'Q') 
               {
                        PutPiece(CurrentSquare, WhiteQueen);
                        CurrentSquare++;

               }
               else if (PiecePositions[PiecePositionsIterator] == 'N') 
               {
                        PutPiece(CurrentSquare, WhiteKnight);
                        CurrentSquare++;
               }
               else if (PiecePositions[PiecePositionsIterator] == 'R') 
               {
                        PutPiece(CurrentSquare, WhiteRook);
                        CurrentSquare++;
               }
               else if (PiecePositions[PiecePositionsIterator] == '1') 
               {
                        CurrentSquare += 1;

               }
               else if (PiecePositions[PiecePositionsIterator] == '2') 
               {
                        CurrentSquare += 2;

               }
               else if (PiecePositions[PiecePositionsIterator] == '3') 
               {
                        CurrentSquare += 3;

               }
               else if (PiecePositions[PiecePositionsIterator] == '4') 
               {
                        CurrentSquare += 4;

               }
               else if (PiecePositions[PiecePositionsIterator] == '5') 
               {
                        CurrentSquare += 5;

               }
               else if (PiecePositions[PiecePositionsIterator] == '6') 
               {
                        CurrentSquare += 6;

               }
               else if (PiecePositions[PiecePositionsIterator] == '7') 
               {
                        CurrentSquare += 7;
               }
               else if (PiecePositions[PiecePositionsIterator] == '8') 
               {
                        CurrentSquare += 8;
               }
        }


        if (FENTokenVector[1] == "w") 
        {
                SideToMove = white;
        } 
        else
        {
                SideToMove = black;
        }

        std::string CastleRights = FENTokenVector[2];

        for (int CastleRightsIterator=0; CastleRightsIterator < CastleRights.length(); CastleRightsIterator++) 
        {
                if (CastleRights[CastleRightsIterator] == 'k') 
                {
                        BlackKingCastleRights = 1;
                }
                else if (CastleRights[CastleRightsIterator] =='q')
                {
                        BlackQueenCastleRights = 1;
                }
                else if (CastleRights[CastleRightsIterator] == 'K')
                {
                        WhiteKingCastleRights = 1;
                }
                else if (CastleRights[CastleRightsIterator] == 'Q')
                {
                        WhiteQueenCastleRights = 1;
                }
        }
}
