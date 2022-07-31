
#include "Interface.hpp"

void ParseUCICommand(std::vector<std::string> TokenVector) 
{
    static Chessboard Board;

    for (int TokenVectorIterator=0; TokenVectorIterator < TokenVector.size(); TokenVectorIterator++) 
    {
        if (TokenVector[TokenVectorIterator] == "uci" || TokenVector[TokenVectorIterator] == "uci\n") 
        {
            std::cout << "id name Mojave\n";
            std::cout << "id author Jacob Evans\n";
            std::cout << "uciok\n";   
        }   
        
        if (TokenVector[TokenVectorIterator] == "isready\n" || TokenVector[TokenVectorIterator] == "isready")
        {
            std::cout << "readyok\n";
        }

        if (TokenVector[TokenVectorIterator] == "position")
        {

            if (TokenVector[TokenVectorIterator+1] == "startpos") 
            {
                Board.ParseFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
            } 
            else 
            {
                std::string FEN = TokenVector[TokenVectorIterator+1] + " " + TokenVector[TokenVectorIterator+2] + " " + TokenVector[TokenVectorIterator+3] + " " + TokenVector[TokenVectorIterator+4] + " " + TokenVector[TokenVectorIterator+5] + " " + TokenVector[TokenVectorIterator+6];
                
                Board.ParseFEN(FEN);
            }       

            
            if (TokenVectorIterator+2 < TokenVector.size()) 
            {
                if (TokenVector[TokenVectorIterator+2] == "moves") 
                {
                    for (int MovesMadeIterator=(TokenVectorIterator+3); MovesMadeIterator < TokenVector.size(); MovesMadeIterator++) 
                    {
                        Move NewMove = Board.CreateMoveFromAlgerbraicNotation(TokenVector[MovesMadeIterator]);

                        Board.DoMove(NewMove);
                    }
                }
            }
        }

        if (TokenVector[TokenVectorIterator] == "go") 
        {
            Move Bestmove = Board.SearchRandom();

            Board.DoMove(Bestmove);
            
            std::cout << "bestmove " << Bestmove.AlgerbraicNotation << "\n";
        }
    }
}


void ParseUCICommand(Chessboard Board, std::vector<std::string> TokenVector) 
{

    for (int TokenVectorIterator=0; TokenVectorIterator < TokenVector.size(); TokenVectorIterator++) 
    {
        if (TokenVector[TokenVectorIterator] == "uci" || TokenVector[TokenVectorIterator] == "uci\n") 
        {
            std::cout << "id name Mojave\n";
            std::cout << "id author Jacob Evans\n";
            std::cout << "uciok\n";   
        }   
        
        if (TokenVector[TokenVectorIterator] == "isready\n" || TokenVector[TokenVectorIterator] == "isready")
        {
            std::cout << "readyok\n";
        }

        if (TokenVector[TokenVectorIterator] == "position")
        {

            if (TokenVector[TokenVectorIterator+1] == "startpos") 
            {
                Board.ParseFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
            } 
            else 
            {
                Board.ParseFEN(TokenVector[TokenVectorIterator+1]);
            }       

            
            if (TokenVectorIterator+2 < TokenVector.size()) 
            {
                if (TokenVector[TokenVectorIterator+2] == "moves") 
                {
                    for (int MovesMadeIterator=(TokenVectorIterator+3); MovesMadeIterator < TokenVector.size(); MovesMadeIterator++) 
                    {
                        Move NewMove = Board.CreateMoveFromAlgerbraicNotation(TokenVector[MovesMadeIterator]);

                        Board.PrintChesssboard();

                        Board.DoMove(NewMove);
                
                        Board.PrintChesssboard();
                    }
                }
            }
        }

        if (TokenVector[TokenVectorIterator] == "go") 
        {
            Move Bestmove = Board.SearchRandom();

            Board.PrintChesssboard();

            Board.DoMove(Bestmove);

            Board.PrintChesssboard();
        }
    }
}

