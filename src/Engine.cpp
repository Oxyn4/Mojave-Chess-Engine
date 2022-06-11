
#include "Chessboard.h"
#include "BoardConcepts.h"
#include "Moves.h"
#include "Bitboard.h"
#include "Interface.h"

#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <thread>

/*
    welcome to the entry point for mojave chess engine

    this file contains driver code for a standard cpp program (main function)
*/


int main() {

    //set program priority

/*    uid_t EUID = geteuid();

    if (EUID == 0) {
        // make process a priority
        int ProcessPriorityUpgradeStatus = nice(-20);
    } else {
        //set to safe value if not root
        int ProcessPriorityUpgradeStatus = nice(1);       
    }
*/
    //precomputed tables and move generation data
    MoveGenerationInit();

    //std::cout << Board.SearchNegaMax(2) << "\n";

    /*
    PrintBitboard(Board.WhiteBlackBitBoard);

    Move TestMove1(b1, a3, white, WhiteKing);

    Board.DoMove(TestMove1);

    PrintBitboard(Board.WhiteBlackBitBoard);

    Move TestMove2(a3, a5, white, WhiteKing);

    Board.DoMove(TestMove2);

    PrintBitboard(Board.WhiteBlackBitBoard);
    */

    //AddBit(Board.PieceTypeBitboardArray[WhitePawn], TestMove.Destination);

    // search for white to depth of 2
    //std::cout << Search_MinMax(Board, 2) << "\n";

    //PrintBitboard(Board.ClassicalGenerateRookMoves(a5, white));

    //AddBit(*Board.PieceTypeBitboardArray[WhitePawn], a1);

    //PrintBitboard(Board.WhitePawnBitBoard);


    //std::cout << "White and black bitboard - pre" << "\n";
    //PrintBitboard(Board.WhiteBlackBitBoard);
    //std::cout << "White knight bitboard - pre" << "\n";
    //PrintBitboard(Board.WhiteKnightBitBoard);
    //std::cout << "Side bitboard array - pre" << "\n";
    //PrintBitboard(Board.WhiteBitBoard);

    //Move Test(g6, e7, white, WhiteKnight);

    //Board.DoMove(Test);                                    
    
    //std::cout << "White and black bitboard - post" << "\n";
    //PrintBitboard(Board.WhiteBlackBitBoard);
    //std::cout << "White knight bitboard - post" << "\n";
    //PrintBitboard(Board.WhiteKnightBitBoard);
    //std::cout << "Side bitboard array - post" << "\n";
    //PrintBitboard(Board.WhiteBitBoard);

    //std::cout << Board.SideToMove << "\n";

    //std::cout << Evaluate(Board) << "\n";                                                                  

    InterfaceLoop();

    return EXIT_SUCCESS;    
}
