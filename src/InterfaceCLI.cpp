
#include "Bitboard.hpp"
#include "BoardConcepts.hpp"
#include "Interface.hpp"
#include <csignal>

void CLI_SIGSEGV_Handler(int SignalNumber) 
{
    std::cout << "\nInvalid Mojave Command Detected\n\n"; 

    std::cout << "Please check supplied arguments\n\n";

    InterfaceLoop();
}

void CommandLineInterface(std::vector<std::string> TokenVector) 
{
    static Chessboard Board;
    
    // due to the nature of the following for loop seg faults are likely to mean that a cli command was entered with incorrext atguments
    //signal(SIGSEGV, CLI_SIGSEGV_Handler);

    // loop over each word collected through stdin
    // 
    // Mojave -> pp a1 WhitePawn
    //
    // we get a vector containing tokens:
    //
    // pp
    // a1
    // WhitePawn
    //
    // we check for command identifiers like "pp"
    //  
    // The position of pp in vector + 1 will equal the first argument
    //
    // The position of pp in vecotr + 2 will equal the second argument
    //
    // etc
    //
    // however if only 1 argument was supplied for a two argument command:
    //
    // TokenVector[TokenVectorIterator+2] = seg fault  
    //
    // hence why we handle segfault signal
    for (int TokenVectorIterator=0; TokenVectorIterator < TokenVector.size(); TokenVectorIterator++) 
    {
        if (TokenVector[TokenVectorIterator] == "info") 
        {
            std::cout << "\nMojave Engine\n\n";

            std::cout << "The author of this engine is Jacob Evans\n\n";
        }

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

        if (TokenVector[TokenVectorIterator] == "pb") 
        {
            Board.PrintInternalBitboards();
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
            std::cout << "\nZobrist hash of current position: " << Board.ZobristHash() << "\n\n";
        }

        if (TokenVector[TokenVectorIterator] == "uci") 
        {
            std::vector<std::string> UCITokenVector;
            
            if (TokenVector.size() > 1) 
            {
                for (int UCITokenVectorIterator=1; UCITokenVectorIterator < TokenVector.size(); UCITokenVectorIterator++) 
                {
                     UCITokenVector.push_back(TokenVector[UCITokenVectorIterator]);
                }
            }
            else
            {
                char UCI_Command[50];
               
                std::cout << "UCI -> ";

                std::cin.getline(UCI_Command, 50);

                std::string UCI_CommandString = UCI_Command;

                std::istringstream CommandStringStream(UCI_CommandString);

                std::string Token;
                
                while (CommandStringStream >> Token)
                {
                    UCITokenVector.push_back(Token);
                }

            } 

            ParseUCICommand(Board, UCITokenVector);
        }

        if (TokenVector[TokenVectorIterator] == "gm") 
        {
           int Square = ConvertSquareMappingToMojaveInteger(TokenVector[TokenVectorIterator+1]);

           PrintBitboard(Board.GetMovesForSquare(Square));
        }

        if (TokenVector[TokenVectorIterator] == "gam")
        {
            std::vector<Move> AllMoves = Board.GetAllMoves();

            for (int AllMovesiterator=0; AllMovesiterator < AllMoves.size(); AllMovesiterator++) 
            {
                AllMoves[AllMovesiterator].PrintMove();
            
            }
            std::cout << "\nTotal amount of moves for position: " << AllMoves.size() << "\n\n";
        }

        if (TokenVector[TokenVectorIterator] == "mm") 
        {
            int Origin = ConvertSquareMappingToMojaveInteger(TokenVector[TokenVectorIterator+1]);

            int Destination = ConvertSquareMappingToMojaveInteger(TokenVector[TokenVectorIterator+2]);

            int PieceType = Board.GetPieceType(Origin);

            int Side;

            if (Side < 6) 
            {
                Side = black;
            }
            else 
            {
                Side = white;
            }

            Move NewMove(Origin, Destination, Side, PieceType);

            NewMove.PrintMove();

            Board.DoMove(NewMove);

        }
     
        if (TokenVector[TokenVectorIterator] == "sr") 
        {
            std::cout << "\nSearching for a random move\n\n";

            Move Bestmove = Board.SearchRandom();

            Bestmove.PrintMove();
            
            Board.DoMove(Bestmove);
        }

        if (TokenVector[TokenVectorIterator] == "exit") 
        {
            exit(EXIT_SUCCESS);
        } 
    } 
}
