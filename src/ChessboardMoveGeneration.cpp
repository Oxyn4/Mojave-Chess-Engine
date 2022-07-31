
#include "Bitboard.hpp"
#include "BoardConcepts.hpp"
#include "Chessboard.hpp"
#include <cstdint>
#include <vector>

uint64_t Chessboard::ClassicalGenerateRookMoves(int square, int side) {
  
    #ifdef DEBUG
      std::cout << "Getting all moves for a " << ConvertMojaveSideRepresentationToText(side) << " rook for square: " << ConvertMojaveIntegerToSquareMapping(square) << "\n";      
      //auto FuncStartPoint = std::chrono::high_resolution_clock::now();
    #endif

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
        int Northlsb = BitScanLSB(&NorthBlockers);
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
        int Southlsb = BitscanMSB(&SouthBlockers);
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
    
    #ifdef DEBUG
        //auto StoppingPoint = std::chrono::high_resolution_clock::now();
        //auto Duration = std::chrono::duration_cast<std::chrono::microseconds>(StoppingPoint - FuncStartPoint);
        //std::cout << "Finished getting moves for a Rook on square: " << square << " in: " << Duration.count()  << " microseconds"  << "\n\n";
    #endif
    
    return FinalBitboard;
}

uint64_t Chessboard::ClassicalGenerateBishopMoves(int Square, int side) {
   
    #ifdef DEBUG
        std::cout << "Getting moves for a " << ConvertMojaveSideRepresentationToText(side) << " bishop on Square " << ConvertMojaveIntegerToSquareMapping(Square) << "\n";
       //auto FuncStartPoint = std::chrono::high_resolution_clock::now();
    #endif

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
    
    #ifdef DEBUG
        //auto StoppingPoint = std::chrono::high_resolution_clock::now();
        //auto Duration = std::chrono::duration_cast<std::chrono::microseconds>(StoppingPoint - FuncStartPoint);
        //std::cout << "Finished getting moves for a Bishop on square: " << Square << " in: " << Duration.count()  << " microseconds"  << "\n\n";
    #endif

    return FinalBitboard;
}

uint64_t Chessboard::ClassicalGenerateQueenMoves(int square, int side) {
    
    #ifdef DEBUG
        std::cout << "Getting moves for a " << ConvertMojaveSideRepresentationToText(side) << " queen on Square " << ConvertMojaveIntegerToSquareMapping(square) << "\n";
        //auto FuncStartPoint = std::chrono::high_resolution_clock::now();
    #endif

    uint64_t Rookpattern = ClassicalGenerateRookMoves(square, side);
    uint64_t Bishoppattern = ClassicalGenerateBishopMoves(square, side);
    uint64_t Queenpattern = Bishoppattern | Rookpattern;
    
    #ifdef DEBUG
        //auto StoppingPoint = std::chrono::high_resolution_clock::now();
        //auto Duration = std::chrono::duration_cast<std::chrono::microseconds>(StoppingPoint - FuncStartPoint);
        //std::cout << "Finished getting moves for a Queen on square: " << square << " in: " << Duration.count()  << " microseconds"  << "\n\n";
    #endif  
  
    return Queenpattern;
}


uint64_t Chessboard::GetKingMoves(int square, int side) {
    
    #ifdef DEBUG
      std::cout << "Getting moves for a " << ConvertMojaveSideRepresentationToText(side) << " King on Square " << ConvertMojaveIntegerToSquareMapping(square) << "\n";
    #endif
    
    uint64_t KingMask = KingMoves[square];
    

    uint64_t KingBitboard = KingMask & ~*SideBitboardArray[side];
    

    return KingBitboard;
}


uint64_t Chessboard::GetKnightMoves(int square, int side) {

    #ifdef DEBUG
      std::cout << "Getting moves for a " << ConvertMojaveSideRepresentationToText(side) << " Knight on Square " << ConvertMojaveIntegerToSquareMapping(square) << "\n";
    #endif

    uint64_t PotentialKnightMoves = KnightMoves[square];

    uint64_t FinalKnightMoves = PotentialKnightMoves & ~*SideBitboardArray[side];

    return FinalKnightMoves;
}


uint64_t Chessboard::GetPawnMoves(int square, int side) {
    #ifdef DEBUG
      std::cout << "Getting moves for a " << ConvertMojaveSideRepresentationToText(side) << " pawn on Square " << ConvertMojaveIntegerToSquareMapping(square) << "\n";
    #endif
    
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

uint64_t Chessboard::GetMovesForSquare(int Square)
{
    int PieceType = GetPieceType(Square);
    
    int Side;

    if (PieceType <= 5) 
    {
        Side = black;
    }
    else 
    {
        Side = white;
    }

    uint64_t Result = (this->*MoveCalculatingFunctions[PieceType])(Square, Side);

    return Result;
}


/*    std::cout << LegalMoveVector.size() << " Amount of moves available in this position for this side" << "\n";

    auto StoppingPoint = std::chrono::high_resolution_clock::now();

    auto Duration = std::chrono::duration_cast<std::chrono::microseconds>(StoppingPoint - FuncStartPoint);

    std::cout << "Finished Calculating Legal moves in " << Duration.count()  << " microseconds"  << "\n\n";
*/
    

std::vector<Move> Chessboard::GetAllMoves()
{
    std::vector<Move> LegalMoveVector;
    for (int SquareIterator=0; SquareIterator < 64; SquareIterator++)
    {
        if (GetBit(&WhiteBlackBitBoard, SquareIterator) == 1)
        {
            int PieceType = GetPieceType(SquareIterator);

            uint64_t MovesForSquare = GetMovesForSquare(SquareIterator); 
    
            int side;

            if (PieceType <= 5)
            {
                side = black;
            }
            else 
            {
                side = white;
            }

            while (MovesForSquare != 0) 
            {
                int SetBit = BitScanLSB(&MovesForSquare);

                Move NewMove(SquareIterator, SetBit, side, PieceType);

                LegalMoveVector.push_back(NewMove);
                
                ResetLSB(&MovesForSquare);
            }
        }
    }
    return LegalMoveVector;
}

std::vector<Move> Chessboard::GetAllSidesMoves(int Side)
{
    std::vector<Move> LegalMoveVector;
    for (int SquareIterator=0; SquareIterator < 64; SquareIterator++)
    {
        if (GetBit(&WhiteBlackBitBoard, SquareIterator) == 1)
        {
            int PieceType = GetPieceType(SquareIterator);

            uint64_t MovesForSquare = GetMovesForSquare(SquareIterator); 
    
            int PieceSide;

            if (PieceType <= 5)
            {
                PieceSide = black;
            }
            else 
            {
                PieceSide = white;
            }

            if (PieceSide == Side) 
            {
                while (MovesForSquare != 0) 
                {
                    int SetBit = BitScanLSB(&MovesForSquare);

                    Move NewMove(SquareIterator, SetBit, PieceSide, PieceType);

                    LegalMoveVector.push_back(NewMove);
                
                    ResetLSB(&MovesForSquare);
                }
        
            }
    
        }
    }
    return LegalMoveVector;
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

std::vector<Move> Chessboard::IsSquareAttacked(int Square) 
{
    std::vector<Move> AllMoves = GetAllMoves();

    std::vector<Move> MovesThatAttackSquare;

    //std::cout << ConvertMojaveIntegerToSquareMapping(Square) << "\n";

    for (int AllMovesIterator=0; AllMovesIterator < AllMoves.size(); AllMovesIterator++)
    {
        AllMoves[AllMovesIterator].PrintMove();

        if (AllMoves[AllMovesIterator].Destination == Square)
        {
            MovesThatAttackSquare.push_back(AllMoves[AllMovesIterator]);
        }
    }

    std::cout << "\nTotal amount of moves that threaten this square: " << MovesThatAttackSquare.size() << "\n\n";

    return MovesThatAttackSquare;
}
