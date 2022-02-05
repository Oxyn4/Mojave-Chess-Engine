
#include "Chessboard.h"
#include "BoardConcepts.h"
#include "Moves.h"
#include "uci.h"

#include <unistd.h>

int main() {

    // make process a priority
    int ProcessPriorityUpgradeStatus = nice(-20);

    if (ProcessPriorityUpgradeStatus != -20) {
        return EXIT_FAILURE;
    }

    MoveGenerationInit();
    Chessboard Board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    UCILoop(Board);

    return EXIT_SUCCESS;    
}
