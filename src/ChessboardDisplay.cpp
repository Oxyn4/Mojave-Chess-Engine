
#include "Chessboard.hpp"

void Chessboard::PrintInternalBitboards() 
{
    for (int BitboardIterator=0; BitboardIterator < 12; BitboardIterator++) 
    {
        std::cout << "\nBitboard for " << ConvertMojavePieceRepresentationToText(BitboardIterator) << "\n\n";

        PrintBitboard(*PieceTypeBitboardArray[BitboardIterator]);
    }
}


void Chessboard::PrintChesssboard()
{
    for (int RankIterator=0; RankIterator < 8; RankIterator++) 
    {
        for (int FileIterator=0; FileIterator < 8; FileIterator++) 
        {
            int Sqaure = RankIterator * 8 + FileIterator;

            int OneOrZero = GetBit(&WhiteBlackBitBoard, Sqaure); 

            if (FileIterator == 0) 
            {
                std::cout << 8 - RankIterator << " | "; 
            }

            if (OneOrZero == 1) 
            {
                int PieceType = GetPieceType(Sqaure);

                std::cout << PieceAsciiSymbols[PieceType] << " ";
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
