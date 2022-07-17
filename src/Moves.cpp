
// definition file
#include "Moves.hpp"

uint64_t KnightMoves[64];
uint64_t KingMoves[64];
uint64_t PawnAttacks[2][64];
uint64_t PawnMoves[2][64];
uint64_t RaysArray[64][8];

int BitboardPieceOffsets[12][8] = {{-9,-7}, {9,7,-9,-7}, {8, -8, 9, -9, -7, 7, 1, -1}, {-1,1,-8,8,9,-7,7,-9}, {-17, -15, -6, 6, 10, -10, 17, 15}, {-1,1,8,-8}, {9,7}, {9,7,-9,-7}, {8, -8, 9, -9, -7, 7, 1, -1}, {-1,1,-8,8,9,-7,7,-9}, {-17, -15, -6, 6, 10, -10, 17, 15}, {-1,1,8,-8}};
int BitboardPieceSpecialOffsets[12][5] = {{-16}, {0}, {2,-2}, {0}, {0}, {2,-3}, {16}, {0}, {2, -2}, {0}, {0}, {-3, 2}};
int OffboardPieceOffsets[12][8] = {{-9,-11}, {-9,9,-11,11}, {-1,1,-9,9,-11,11,10,-10}, {-1,1,-9,9,-11,11,10,-10}, {19, 21, -8, 8, -19, -21, 12, -12}, {-1,1,-10, 10}, {9,11}, {-9,9,-11,11}, {-1,1,-9,9,-11,11,10,-10}, {-1,1,-9,9,-11,11,10,-10}, {19, 21, -8, 8, -19, -21, 12, -12}, {-1,1,-10, 10}};
int OffboardPieceSpecialOffsets[12][5] = {{-20}, {0}, {2,-2}, {0}, {0}, {2,-3}, {20}, {0}, {2, -2}, {0}, {0}, {-3, 2}};

// precomputate a bitboard for each square which highlights where a knight can move
void PrecomputateKnightMoves() {

    #define KNIGHT_MOVES_INITIALIZED 

    #ifdef DEBUG
        auto FuncStartPoint = std::chrono::high_resolution_clock::now();

        std::cout << "Calculating legal knight moves for each square " << "\n";
    #endif

    // special offsets only applicable when
    // piece on a specific file
    // used to prevent bitboard rank wrapping issue
    int FILE_A_KnightOffsets[4] = {-15, 10, 17, -6};
    int FILE_B_KnightOffsets[6] = {-15, 10, 17, -6, -17, 15};

    int FILE_G_KnightOffsets[6] = {6, 15, 17, -10, -17, -15};
    int FILE_H_KnightOffsets[4] = {6, 15, -17, -10};

    for (int CurrentSquare = 0; CurrentSquare < 64; CurrentSquare++) {

        uint64_t KnightBitboard = 0ULL;

        KnightBitboard |= (1ULL << CurrentSquare) ? KnightBitboard ^= (1ULL << CurrentSquare) : 0; 

        // if the current square is in the A file
        if (KnightBitboard & FILE_A) {
            for (int y=0; y<4; y++ ) {
                if (CurrentSquare + FILE_A_KnightOffsets[y] < 64 && CurrentSquare + FILE_A_KnightOffsets[y] > 0) {
                    KnightBitboard |= (1ULL << (CurrentSquare + FILE_A_KnightOffsets[y])) ? KnightBitboard ^= (1ULL << (CurrentSquare + FILE_A_KnightOffsets[y])) : 0;
                    //std::cout << CurrentSquare + FILE_A_KnightOffsets[y] << "\n";
                }
            }
        } else if (FILE_B & KnightBitboard) {
            for (int r = 0; r <6; r++) {
                if (CurrentSquare + FILE_B_KnightOffsets[r] < 64 && CurrentSquare + FILE_B_KnightOffsets[r] > 0) {
                    KnightBitboard |= (1ULL << (CurrentSquare + FILE_B_KnightOffsets[r])) ? KnightBitboard ^= (1ULL << (CurrentSquare + FILE_B_KnightOffsets[r])) : 0;
                    //std::cout << CurrentSquare + FILE_B_KnightOffsets[r] << "\n";
                }
            }
        } else if (FILE_G & KnightBitboard) {
            for (int y=0; y< 6; y++) {
                if (CurrentSquare + FILE_G_KnightOffsets[y] < 64 && CurrentSquare + FILE_G_KnightOffsets[y] > 0) {
                    KnightBitboard |= (1ULL << (CurrentSquare + FILE_G_KnightOffsets[y])) ? KnightBitboard ^= (1ULL << (CurrentSquare + FILE_G_KnightOffsets[y])) : 0;
                    //std::cout << CurrentSquare + FILE_G_KnightOffsets[y] << "\n";
                }
            }
        } else if (KnightBitboard & FILE_H) {
            for (int u=0;u<4;u++) {
                if (CurrentSquare + FILE_H_KnightOffsets[u] < 64 && CurrentSquare + FILE_H_KnightOffsets[u] > 0) {
                    KnightBitboard |= (1ULL << (CurrentSquare + FILE_H_KnightOffsets[u])) ? KnightBitboard ^= (1ULL << (CurrentSquare + FILE_H_KnightOffsets[u])) : 0; 
                    //std::cout << CurrentSquare + FILE_H_KnightOffsets[u] << "\n";
                }
            }
        } else {
            for (int p=0;p<8;p++) {
                if (CurrentSquare + BitboardPieceOffsets[WhiteKnight][p] < 64 && CurrentSquare + BitboardPieceOffsets[WhiteKnight][p] > 0) {
                    KnightBitboard |= (1ULL << (CurrentSquare + BitboardPieceOffsets[WhiteKnight][p])) ? KnightBitboard ^= (1ULL << (CurrentSquare + BitboardPieceOffsets[WhiteKnight][p])) : 0; 
                    //std::cout << CurrentSquare + BitboardPieceOffsets[WhiteKnight][p] << "\n";
                }
            }
        }

        KnightBitboard ^= (1ULL << CurrentSquare);

        KnightMoves[CurrentSquare] = KnightBitboard;

        //PrintBitboard(KnightBitboard);
    }

    #ifdef DEBUG
        auto StoppingPoint = std::chrono::high_resolution_clock::now();

        auto Duration = std::chrono::duration_cast<std::chrono::microseconds>(StoppingPoint - FuncStartPoint);

        std::cout << "Finished Calculating Knight moves in: " << Duration.count() << " microseconds" << "\n";
        std::cout << "\n";
    #endif
}

void PrecomputateKingMoves() {

    #define KING_MOVES_INITIALIZED

    #ifdef DEBUG
        auto FuncStartPoint = std::chrono::high_resolution_clock::now();

        std::cout << "Calculating legal knight moves for each square" << "\n";
    #endif

    int FILE_A_OFFSETS[5] = {8,-8,-7,9,1};
    int FILE_H_OFFSETS[5] = {-1,8,-8,7,-9};

    for (int KingCurrentSquare=0; KingCurrentSquare<64; KingCurrentSquare++) {
        uint64_t KingBitboard = 0ULL;

        KingBitboard |= (1ULL << KingCurrentSquare) ? KingBitboard ^= (1ULL << KingCurrentSquare) : 0; 

        if (KingBitboard & FILE_A) {
            for (int u=0;u<5;u++) {
                if (KingCurrentSquare + FILE_A_OFFSETS[u] < 64 && KingCurrentSquare + FILE_A_OFFSETS[u] > 0) {
                    KingBitboard |= (1ULL << (KingCurrentSquare + FILE_A_OFFSETS[u])) ? KingBitboard ^= (1ULL << (KingCurrentSquare + FILE_A_OFFSETS[u])) : 0; 
                    //std::cout << KingCurrentSquare + FILE_A_OFFSETS[u] << "\n";
                }
            }
        } else if (KingBitboard & FILE_H) {
            for (int g=0; g<5;g++) {
                if (KingCurrentSquare + FILE_H_OFFSETS[g] < 64 && KingCurrentSquare + FILE_H_OFFSETS[g] > 0) {
                    KingBitboard |= (1ULL << (KingCurrentSquare + FILE_H_OFFSETS[g])) ? KingBitboard ^= (1ULL << (KingCurrentSquare + FILE_H_OFFSETS[g])) : 0; 
                    //std::cout << KingCurrentSquare + FILE_H_OFFSETS[g] << "\n";
                }
            }
        } else {
            for (int y=0;y<8;y++) {
                if (KingCurrentSquare + BitboardPieceOffsets[WhiteKing][y] < 64 && KingCurrentSquare + BitboardPieceOffsets[WhiteKing][y] > 0) {
                    KingBitboard |= (1ULL << (KingCurrentSquare + BitboardPieceOffsets[WhiteKing][y])) ? KingBitboard ^= (1ULL << (KingCurrentSquare + BitboardPieceOffsets[WhiteKing][y])) : 0; 
                    //std::cout << KingCurrentSquare + BitboardPieceOffsets[WhiteKing][y] << "\n";
                }
            }
        }

        KingBitboard ^= (1ULL << KingCurrentSquare);

        KingMoves[KingCurrentSquare] = KingBitboard;
    }

    #ifdef DEBUG
        auto StoppingPoint = std::chrono::high_resolution_clock::now();

        auto Duration = std::chrono::duration_cast<std::chrono::microseconds>(StoppingPoint - FuncStartPoint);

        std::cout << "Finished Calculating King moves in: " << Duration.count() << " microseconds"  << "\n";
        std::cout << "\n";
    #endif 
}

void PrecomputatePawnAttacks() {

    #define PAWN_ATTACKS_INITIALIZED

    #ifdef DEBUG
        auto FuncStartPoint = std::chrono::high_resolution_clock::now();
    
        std::cout << "Calculating legal pawn moves for each square" << "\n";
    #endif

    int FILE_OFFSETS[2][2] = {{-7, -9}, {9, 7}};
    int OFFSETS[2][2] {{-7,-9},{9,7}};

    for (int SideIndex =0; SideIndex <2; SideIndex++) {
        for (int SquareIndex = 0; SquareIndex < 64; SquareIndex++)
        {
            uint64_t PawnBitboard = 0ULL; 

            PawnBitboard |= (1ULL << SquareIndex) ? PawnBitboard ^= (1ULL << SquareIndex) : 0; 

            if (FILE_A & PawnBitboard) {
                if (FILE_OFFSETS[SideIndex][1] + SquareIndex > 0 && FILE_OFFSETS[SideIndex][1] + SquareIndex < 64) {
                    PawnBitboard |= (1ULL << (SquareIndex + FILE_OFFSETS[SideIndex][0])) ? PawnBitboard ^= (1ULL << (SquareIndex + FILE_OFFSETS[SideIndex][0])) : 0;
                    //std::cout << FILE_OFFSETS[SideIndex][1] << "\n";
                }
                
            } else if (FILE_H & PawnBitboard) {
                if (FILE_OFFSETS[SideIndex][2] + SquareIndex > 0 && FILE_OFFSETS[SideIndex][2] + SquareIndex < 64) { 
                    PawnBitboard |= (1ULL << (SquareIndex + FILE_OFFSETS[SideIndex][1])) ? PawnBitboard ^= (1ULL << (SquareIndex + FILE_OFFSETS[SideIndex][1])) : 0; 
                    //std::cout << SquareIndex + FILE_OFFSETS[SideIndex][2] << "\n";
                }
            } else {
                for (int FILE_OFFSET = 0; FILE_OFFSET < 2; FILE_OFFSET++) {
                    if (OFFSETS[SideIndex][FILE_OFFSET] + SquareIndex > 0 && OFFSETS[SideIndex][FILE_OFFSET] + SquareIndex < 64) {
                        PawnBitboard |= (1ULL << (SquareIndex + OFFSETS[SideIndex][FILE_OFFSET])) ? PawnBitboard ^= (1ULL << (SquareIndex + OFFSETS[SideIndex][FILE_OFFSET])) : 0; 
                        //std::cout << OFFSETS[SideIndex][FILE_OFFSET] + SquareIndex << "\n";
                    }
                }
            }

        PawnBitboard ^= (1ULL << SquareIndex);

        PawnAttacks[SideIndex][SquareIndex] = PawnBitboard;

        }  
    }

    #ifdef DEBUG
        auto StoppingPoint = std::chrono::high_resolution_clock::now();

        auto Duration = std::chrono::duration_cast<std::chrono::microseconds>(StoppingPoint - FuncStartPoint);

        std::cout << "Finished Calculating Pawn Attacks in: " << Duration.count()  << " microseconds"  << "\n";
        std::cout << "\n";
    #endif
}

void PrecomputatePawnMoves() {

    #define PAWN_MOVES_INITIALIZED


    #ifdef DEBUG
        std::cout << "Calculating all legal pawn moves for each square" << "\n";
        auto FuncStartPoint = std::chrono::high_resolution_clock::now();
    #endif

    int OFFSETS[2][2] = {{-8, -16}, {8, 16}}; 

    for (int SideIndex = 0; SideIndex < 2; SideIndex++)
    {
        for (int SquareIndex = 0; SquareIndex < 64; SquareIndex++)
        {
            uint64_t PawnBitboard = 0ULL;

            PawnBitboard |= (1ULL << SquareIndex) ? PawnBitboard ^= (1ULL << SquareIndex) : 0;           

            if (PawnBitboard & RANK_2 && SideIndex != black) {
                if (SquareIndex + OFFSETS[0][1] < 64 && SquareIndex + OFFSETS[0][1] > 0) {
                    PawnBitboard  |=(1ULL << (SquareIndex + OFFSETS[SideIndex][1])) ? PawnBitboard ^= (1ULL << (SquareIndex + OFFSETS[SideIndex][1])) : 0; 
                }
            } 
            if (SideIndex != black) {
                if (SquareIndex + OFFSETS[0][0] < 64 && SquareIndex + OFFSETS[0][0] > 0) {
                    PawnBitboard |= (1ULL << (SquareIndex + OFFSETS[SideIndex][0])) ? PawnBitboard ^= (1ULL << (SquareIndex + OFFSETS[SideIndex][0])) : 0; 
                }
            } 

            if (PawnBitboard & RANK_7 && SideIndex != white) {
                if (SquareIndex + OFFSETS[1][1] < 64 && SquareIndex + OFFSETS[1][1] > 0) {
                    PawnBitboard |= (1ULL << (SquareIndex + OFFSETS[SideIndex][1])) ? PawnBitboard ^= (1ULL << (SquareIndex + OFFSETS[SideIndex][1])) : 0; 
                }
            } 
            if (SideIndex != white) {
                if (SquareIndex + OFFSETS[1][0] < 64 && SquareIndex + OFFSETS[1][0] > 0) {
                    PawnBitboard |= (1ULL << (SquareIndex + OFFSETS[SideIndex][0])) ? PawnBitboard ^= (1ULL << (SquareIndex + OFFSETS[SideIndex][0])) : 0; 
                }
            }

            PawnBitboard ^= (1ULL << SquareIndex);

            PawnMoves[SideIndex][SquareIndex] = PawnBitboard;
        }
        
    }
    
    #ifdef DEBUG
        auto StoppingPoint = std::chrono::high_resolution_clock::now();

        auto Duration = std::chrono::duration_cast<std::chrono::microseconds>(StoppingPoint - FuncStartPoint);

        std::cout << "Finished Calculating Pawn Moves in: " << Duration.count()  << " microseconds"  << "\n\n";
    #endif
}

// This function fills up a rook move array
// for each square it generates every possible combination of blockers
void GenerateRaysArray() {
    
    #define RAYS_ARRAY_INITIALIZED

    #ifdef DEBUG
        std::cout << "Calculating all RaysArray for each direction for each square" << "\n";

        auto FuncStartPoint = std::chrono::high_resolution_clock::now();
    #endif

    int RAY_OFFSETS[8] = {-8, -7, 1, 9, 8, 7, -1, -9};

    for (int SquareIndex = 0; SquareIndex < 64; SquareIndex++)
    {

        int Count = 1;

        // ! North

        uint64_t NorthBitboard = 0ULL;

        NorthBitboard |= (1ULL << SquareIndex) ? NorthBitboard ^= (1ULL << SquareIndex) : 0; 

        for (int SoutheastIncrement = 0; SoutheastIncrement < 8; SoutheastIncrement++) {
            if (NorthBitboard & RANK_8) {
                Count = 1;                       
            } else {
                NorthBitboard |= (1ULL << SquareIndex + (RAY_OFFSETS[North] * Count)) ? NorthBitboard ^= (1ULL << SquareIndex + (RAY_OFFSETS[North] * Count)) : 0; 
                Count += 1;  
            }        
        }

        NorthBitboard ^= (1ULL << SquareIndex);

        RaysArray[SquareIndex][North] = NorthBitboard;

        // ! northeast

        uint64_t NortheastBitboard = 0ULL;

        NortheastBitboard |= (1ULL << SquareIndex) ? NortheastBitboard ^= (1ULL << SquareIndex) : 0; 

        for (int NortheastIncrement = 0; NortheastIncrement < 8; NortheastIncrement++) {
            if (NortheastBitboard & FILE_H || NortheastBitboard & RANK_8) {
                Count = 1;
            } else {
                if (SquareIndex + (RAY_OFFSETS[Northeast] * Count) >= 0) {
                    NortheastBitboard |= (1ULL << SquareIndex + (RAY_OFFSETS[Northeast] * Count)) ? NortheastBitboard ^= (1ULL << SquareIndex + (RAY_OFFSETS[Northeast] * Count)) : 0; 
                    Count += 1;
                }
            }                    
        }

        NortheastBitboard ^= (1ULL << SquareIndex);

        RaysArray[SquareIndex][Northeast] = NortheastBitboard;

        // ! east

        uint64_t EastBitboard = 0ULL;

        EastBitboard |= (1ULL << SquareIndex) ? EastBitboard ^= (1ULL << SquareIndex) : 0; 

        for (int EastIncrement = 0; EastIncrement < 8; EastIncrement++) {
            if (EastBitboard & FILE_H) {
                Count = 1;                       
            } else {
                EastBitboard |= (1ULL << SquareIndex + (RAY_OFFSETS[East] * Count)) ? EastBitboard ^= (1ULL << SquareIndex + (RAY_OFFSETS[East] * Count)) : 0; 
                Count += 1;  
            }        
        }

        EastBitboard ^= (1ULL << SquareIndex);

        RaysArray[SquareIndex][East] = EastBitboard;

        // ! Southeast

        uint64_t SoutheastBitboard = 0ULL;

        SoutheastBitboard |= (1ULL << SquareIndex) ? SoutheastBitboard ^= (1ULL << SquareIndex) : 0; 

        for (int SoutheastIncrement = 0; SoutheastIncrement < 8; SoutheastIncrement++) {
            if (SoutheastBitboard & RANK_1 || SoutheastBitboard & FILE_H) {
                Count = 1;                       
            } else {
                SoutheastBitboard |= (1ULL << SquareIndex + (RAY_OFFSETS[Southeast] * Count)) ? SoutheastBitboard ^= (1ULL << SquareIndex + (RAY_OFFSETS[Southeast] * Count)) : 0; 
                Count += 1;  
            }        
        }

        SoutheastBitboard ^= (1ULL << SquareIndex);

        RaysArray[SquareIndex][Southeast] = SoutheastBitboard;

        // ! south

        uint64_t SouthBitboard = 0ULL;

        SouthBitboard |= (1ULL << SquareIndex) ? SouthBitboard ^= (1ULL << SquareIndex) : 0; 

        for (int SouthIncrement = 0; SouthIncrement < 8; SouthIncrement++) {
            if (SouthBitboard & RANK_1) {
                Count = 1;                       
            } else {
                SouthBitboard |= (1ULL << SquareIndex + (RAY_OFFSETS[South] * Count)) ? SouthBitboard ^= (1ULL << SquareIndex + (RAY_OFFSETS[South] * Count)) : 0; 
                Count += 1;  
            }        
        }

        SouthBitboard ^= (1ULL << SquareIndex);

        RaysArray[SquareIndex][South] = SouthBitboard;

        // ! southwest

        uint64_t SouthwestBitboard = 0ULL;

        SouthwestBitboard |= (1ULL << SquareIndex) ? SouthwestBitboard ^= (1ULL << SquareIndex) : 0; 

        for (int SouthIncrement = 0; SouthIncrement < 8; SouthIncrement++) {
            if (SouthwestBitboard & RANK_1 || SouthwestBitboard & FILE_A) {
                Count = 1;                       
            } else {
                SouthwestBitboard |= (1ULL << SquareIndex + (RAY_OFFSETS[Southwest] * Count)) ? SouthwestBitboard ^= (1ULL << SquareIndex + (RAY_OFFSETS[Southwest] * Count)) : 0; 
                Count += 1;  
            }        
        }

        SouthwestBitboard ^= (1ULL << SquareIndex);

        RaysArray[SquareIndex][Southwest] = SouthwestBitboard;

        // ! west

        uint64_t WestBitboard = 0ULL;

        WestBitboard |= (1ULL << SquareIndex) ? WestBitboard ^= (1ULL << SquareIndex) : 0; 

        for (int SouthIncrement = 0; SouthIncrement < 8; SouthIncrement++) {
            if (WestBitboard & RANK_1 || WestBitboard & FILE_A) {
                Count = 1;                       
            } else {
                WestBitboard |= (1ULL << SquareIndex + (RAY_OFFSETS[West] * Count)) ? WestBitboard ^= (1ULL << SquareIndex + (RAY_OFFSETS[West] * Count)) : 0; 
                Count += 1;  
            }        
        }

        WestBitboard ^= (1ULL << SquareIndex);

        RaysArray[SquareIndex][West] = WestBitboard;

        // ! Northwest

        uint64_t NorthwestBitboard = 0ULL;

        NorthwestBitboard |= (1ULL << SquareIndex) ? NorthwestBitboard ^= (1ULL << SquareIndex) : 0; 

        for (int SouthIncrement = 0; SouthIncrement < 8; SouthIncrement++) {
            if (NorthwestBitboard & RANK_8 || NorthwestBitboard & FILE_A) {
                Count = 1;                       
            } else {
                NorthwestBitboard |= (1ULL << SquareIndex + (RAY_OFFSETS[Northwest] * Count)) ? NorthwestBitboard ^= (1ULL << SquareIndex + (RAY_OFFSETS[Northwest] * Count)) : 0; 
                Count += 1;  
            }        
        }

        NorthwestBitboard ^= (1ULL << SquareIndex);

        RaysArray[SquareIndex][Northwest] = NorthwestBitboard;
    }
    
    #ifdef DEBUG
        auto StoppingPoint = std::chrono::high_resolution_clock::now();

        auto Duration = std::chrono::duration_cast<std::chrono::microseconds>(StoppingPoint - FuncStartPoint);

        std::cout << "Finished Calculating RaysArray boards in: " << Duration.count()  << " microseconds"  << "\n\n";
    #endif
}

/*

    function calls all other move generation related functions  

*/
void MoveGenerationInit() {
    
    #ifdef DEBUG
        std::cout << "Starting Precomputating Move dats\n\n";

        auto FuncStartPoint = std::chrono::high_resolution_clock::now();
    #endif

    GenerateRaysArray();

    PrecomputateKnightMoves();
    PrecomputatePawnMoves();
    PrecomputatePawnAttacks();
    PrecomputateKingMoves();

    #define MOVE_FUNCTIONS_INITIALIZED 

    #ifdef DEBUG
        auto StoppingPoint = std::chrono::high_resolution_clock::now();

        auto Duration = std::chrono::duration_cast<std::chrono::microseconds>(StoppingPoint - FuncStartPoint);

        std::cout << "Finished Calculating Precomputated data boards in: " << Duration.count()  << " microseconds"  << "\n\n";
    #endif

}
