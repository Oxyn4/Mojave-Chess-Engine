/*
    the centeral class of mojave engine a chessbaord class is in charge of:

    ~ storing, managing, tracking the internel state of the bitboards
    ~ generating moves using those bitboards and move data calculated in move.cpp
    ~ evaluating the board position mapping a score to a position 
    ~ searching the available moves using generation functions and evaluation functions to choose an optimal move

    this class is the largest part of the program so the implementation is divised between several files


*/


#include "Chessboard.hpp"


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
