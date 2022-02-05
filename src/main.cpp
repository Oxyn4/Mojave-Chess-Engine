
#include "Chessboard.h"
#include "BoardConcepts.h"
#include "Moves.h"
#include "uci.h"

#include <thread>

int main() {

    MoveGenerationInit();
    Chessboard Board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    UCILoop(Board);

    return EXIT_SUCCESS;    
}
