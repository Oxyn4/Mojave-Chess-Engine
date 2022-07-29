/*
    this file contains Data structures and values that help convert human chess concepts
    like ranks files and sqyaure notations (a1,h8) to name a few to computer readable formats
    like numbers etc
*/


#include "BoardConcepts.hpp"


int GetRankOfSquareNumber(int SqaureNumber) 
{
    return std::ceil(SqaureNumber / 8);
}

int GetFileOfSquareNumber(int SqaureNumber)
{
    return SqaureNumber % 8 == 0 ? 8 : SqaureNumber % 8;
}

std::string ConvertMojaveSideRepresentationToText(int Side) 
{
    switch (Side) {
        case black:
            return "black";
        case white:
            return "white";
    }
    return "";
}

int ConvertSquareMappingToMojaveInteger(std::string SqaureNumber) 
{
    for (int SquareMappingArrayIterator=0; SquareMappingArrayIterator < 64; SquareMappingArrayIterator++) 
    {
        if (SqaureMappingArray[SquareMappingArrayIterator] == SqaureNumber) {return SquareMappingArrayIterator;}
    }
    return -1;
} 

int ConvertPieceTextToMojaveInteger(std::string PieceText) 
{
    
    if (PieceText == "BlackPawn") 
    {
            return 0;
    } 
    else if (PieceText == "BlackBishop") 
    {
            return 1; 
    }
    else if (PieceText == "BlackKing") 
    {
            return 2;
    }
    else if (PieceText == "BlackQueen")
    {
            return 3; 
    } 
    else if (PieceText == "BlackKnight")
    {
            return 4; 
    }
    else if (PieceText == "BlackRook")
    {
            return 5;
    }
    else if (PieceText == "WhitePawn")
    {
            return 6;
    } 
    else if (PieceText == "WhiteBishop")
    {
            return 7;
    }
    else if (PieceText == "WhiteKing")
    {
            return 8;
    }
    else if (PieceText == "WhiteQueen") 
    {
            return 9; 
    }
    else if (PieceText == "WhiteKnight")
    {
            return 10;
    }
    else if (PieceText == "WhiteRook") 
    {
            return 11; 
    }


}

std::string ConvertMojavePieceRepresentationToText(int PieceType) 
{
    switch (PieceType) {
        case 0:
            return "Black pawn";
            break;
        case 1:
            return "Black Bishop"; 
            break;
        case 2:
            return "Black King";
            break;
        case 3:
            return "Black Queen"; 
            break;
        case 4:
            return "Black Knight"; 
            break;
        case 5:
            return "Black Rook";
            break;
        case 6:
            return "white Pawn";
            break;
        case 7:
            return "White Bishop";
            break;
        case 8:
            return "White King";
            break;
        case 9:
            return "White Queen"; 
            break;
        case 10:
            return "White Knight";
            break;
        case 11:
            return  "White Rook"; 
            break;
    }
    return ""; 
}

void PrintPiecetype(int PieceType) 
{
    switch (PieceType) {
        case 0:
            std::cout << "PieceType: Black Pawn" << "\n";
            break;
        case 1:
            std::cout << "PieceType: Black Bishop" << "\n"; 
            break;
        case 2:
            std::cout << "PieceType: Black King" << "\n";
            break;
        case 3:
            std::cout << "PieceType: Black Queen" << "\n"; 
            break;
        case 4:
            std::cout << "PieceType: Black Knight" << "\n"; 
            break;
        case 5:
            std::cout << "PieceType: Black Rook" << "\n";
            break;
        case 6:
            std::cout << "PieceType: White Pawn"  << "\n";
            break;
        case 7:
            std::cout << "PieceType: White Bishop" << "\n";
            
            break;
        case 8:
            std::cout << "PieceType: White King" << "\n";
            break;
        case 9:
            std::cout << "PieceType: White Queen" << "\n"; 
            break;
        case 10:
            std::cout << "PieceType: White Knight" << "\n";
            break;
        case 11:
            std::cout << "PieceType: White Rook" << "\n"; 
            break;
    }
}

std::string PieceAsciiSymbols[12] = {"♙","♗","♔","♕","♘","♖","♟","♝","♚","♛","♞","♜",};

// allows convertion of rank notation a-h to numbers mojave can use
std::map<char, int> FileNotationConversion = {{'a', 0},{'b', 1},{'c', 2},{'d', 3},{'e', 4},{'f', 5},{'g', 6},{'h', 7}};

// https://www.chessprogramming.org/Square_Mapping_Considerations
// chess board square zero normaly is a1 
// mojave maps square one as a8
// so we need to reverse the rank
std::map<int, int> SquareMappingConversionTable = {{1,7},{2, 6},{3, 5},{4, 4},{5, 3},{6, 2},{7, 1},{8, 0}};

std::string SqaureMappingArray[64] = {"a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8","a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7","a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6","a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5","a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4","a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3","a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2","a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1"};

Move::Move(std::string AlgerbraicNotationValue) 
{

    std::string OriginAlgerbraicNotation = AlgerbraicNotationValue.substr(0, 2);
    std::string DestinationAlgerbraicNotation = AlgerbraicNotationValue.substr(2, 4);

    AlgerbraicNotation = AlgerbraicNotationValue;

    //std::cout << OriginAlgerbraicNotation << "\n";
    //std::cout << DestinationAlgerbraicNotation << "\n";

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
}

std::map<int, int> ReverseSquareMappingConversionTable = {{7,1},{6,2},{5,3},{4,4},{3,5},{2,6},{1,7}};

std::map<int, char> ReverseFileNotationConversion = {{0, 'a'},{1, 'b'},{2, 'c'},{3, 'd'},{4, 'e'},{5,'f'},{6,'g'},{7,'h'}};

void Move::CreateAlgerbraicNotation() 
{    
    std::string orginNotation = SqaureMappingArray[Origin];
    std::string DestinationNotation = SqaureMappingArray[Destination];

    //AlgerbraicNotation + ConvertedOriginFile; 
    //AlgerbraicNotation + CharConvertedOriginRank; 
    //AlgerbraicNotation + ConvertedDestinationFile; 
    //AlgerbraicNotation + CharConvertedDestinationRank;
    
    AlgerbraicNotation = orginNotation + DestinationNotation;

    //std::cout << AlgerbraicNotation << "\n";
}

void Move::PrintMove() 
{
    // if the 
    //#ifndef DEBUG
        //return;
    //#endif


    std::cout << "\nMove: " << AlgerbraicNotation << "\n\n"; 

    for (int PiecePosition=0; PiecePosition < 2; PiecePosition++)
    {
        for (int SquareMappingConversionIterator=0; SquareMappingConversionIterator < 64; SquareMappingConversionIterator++) 
        {
            int Square;    
        
            if (PiecePosition == 0)
            {
                Square = Origin; 
            } 
            else 
            {
                Square = Destination;
            }

            if (Square == SquareMappingConversionIterator) 
            {
                if (PiecePosition == 0) 
                {
                    std::cout << "    Origin:\n";
                    std::cout << "        Origin: " << SqaureMappingArray[SquareMappingConversionIterator] << "\n";
                    std::cout << "        Mojave Square Notation: " << Square << " \n\n";
                } 
                else
                {
                    std::cout << "    Destination:\n";
                    std::cout << "        Destination: " << SqaureMappingArray[SquareMappingConversionIterator] << "\n";
                    std::cout << "        Mojave Sqaure Notation: " << Square << " \n\n";
                } 
            }
        }
    }

    std::cout << "    PieceType:\n";

    switch (PieceType) {
        case 0:
            std::cout << "        PieceType: Black Pawn" << "\n";
            std::cout << "        Mojave Notation: " << PieceType << "\n"; 
            break;
        case 1:
            std::cout << "        PieceType: Black Bishop" << "\n"; 
            std::cout << "        Mojave Noation: " << PieceType << "\n"; 
            break;
        case 2:
            std::cout << "        PieceType: Black King" << "\n";
            std::cout << "        Mojave Notation: " << PieceType << "\n";
            break;
        case 3:
            std::cout << "        PieceType: Black Queen" << "\n"; 
            std::cout << "        Mojave Notation: " << PieceType << "\n";
            break;
        case 4:
            std::cout << "        PieceType: Black Knight" << "\n"; 
            std::cout << "        Mojave Notation: " << PieceType << "\n";
            break;
        case 5:
            std::cout << "        PieceType: Black Rook" << "\n";
            std::cout << "        Mojave Notation: " << PieceType << "\n";
            break;
        case 6:
            std::cout << "        PieceType: White Pawn"  << "\n";
            std::cout << "        Mojave Notation: " << PieceType << "\n";
            break;
        case 7:
            std::cout << "        PieceType: White Bishop" << "\n";
            std::cout << "        Mojave Notation: " << PieceType << "\n";
            
            break;
        case 8:
            std::cout << "        PieceType: White King" << "\n";
            std::cout << "        Mojave Notation: " << PieceType << "\n";
            break;
        case 9:
            std::cout << "        PieceType: White Queen" << "\n"; 
            std::cout << "        Mojave Notation: " << PieceType << "\n";
            break;
        case 10:
            std::cout << "        PieceType: White Knight" << "\n";
            std::cout << "        Mojave Notation: " << PieceType << "\n";
            break;
        case 11:
            std::cout << "        PieceType: White Rook" << "\n"; 
            std::cout << "        Mojave Notation: " << PieceType << "\n"; 
            
            break;
    }
    std::cout << "\n\n";    
}
