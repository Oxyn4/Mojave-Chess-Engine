
#include "Chessboard.h"
#include "BoardConcepts.h"
#include "Moves.h"
#include "uci.h"
#include "Eval.h"
#include "search.h"


#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <thread>

int main() {

    //set program priority

    uid_t EUID = geteuid();

    if (EUID == 0) {
        // make process a priority
        int ProcessPriorityUpgradeStatus = nice(-20);
    } else {
        //set to safe value if not root
        int ProcessPriorityUpgradeStatus = nice(1);       
    }

    //precomputed tables and move generation data
    MoveGenerationInit();
    
    // create a chessboard object
    Chessboard Board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

    //std::thread UCIThread(UCILoop, &Board);

    //UCIThread.join();

    return EXIT_SUCCESS;    
}
