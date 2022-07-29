
#include "Interface.hpp"

void CommandLineInterface(std::vector<std::string> TokenVector) 
{
    static Chessboard Board;

    for (int TokenVectorIterator=0; TokenVectorIterator < TokenVector.size(); TokenVectorIterator++) 
    {
        if (TokenVector[TokenVectorIterator] == "f") 
        {
            if (TokenVector[TokenVectorIterator+1] == "startpos") 
            {
                Board.ParseFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
            }
            else 
            {
                Board.ParseFEN(TokenVector[TokenVectorIterator+1]);
            }
        }

        if (TokenVector[TokenVectorIterator] == "p") 
        {
            Board.PrintChesssboard();
        }


        if (TokenVector[TokenVectorIterator] == "pp") 
        {
            int Origin = ConvertSquareMappingToMojaveInteger(TokenVector[TokenVectorIterator+1]);
        
            int PieceType = ConvertPieceTextToMojaveInteger(TokenVector[TokenVectorIterator+2]);
        
            Board.PutPiece(Origin, PieceType);
        }

        if (TokenVector[TokenVectorIterator] == "wp") 
        {
            int Square = ConvertSquareMappingToMojaveInteger(TokenVector[TokenVectorIterator+1]);
            
            Board.WipePiece(Square);
        }
        
        if (TokenVector[TokenVectorIterator] == "cl") 
        {
            Board.ClearBoard();
        } 

        if (TokenVector[TokenVectorIterator] == "z") 
        {
            std::cout << "\n" << Board.ZobristHash() << "\n\n";
        }

        if (TokenVector[TokenVectorIterator] == "uci") 
        {
            std::vector<std::string> UCITokenVector;

            for (int UCITokenVectorIterator=1; UCITokenVectorIterator < UCITokenVectorIterator; UCITokenVectorIterator++) 
            {
                 UCITokenVector.push_back(TokenVector[UCITokenVectorIterator]);
            }

            ParseUCICommand(Board, UCITokenVector);
        }

        if (TokenVector[TokenVectorIterator] == "exit") 
        {
            exit(EXIT_SUCCESS);
        } 
    } 
}
