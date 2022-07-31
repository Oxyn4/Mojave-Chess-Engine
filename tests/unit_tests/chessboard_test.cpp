#include <gtest/gtest.h>

#include "../../src/Chessboard.hpp"

class ChessboardTest : public ::testing::Test {
    protected:
        Chessboard TestBoard;

        void SetUp() 
        {

        }

        void TearDown() 
        {

        }
};

TEST_F(ChessboardTest, ZobristHash) 
{
    TestBoard.ParseFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

    int ZobristValue = TestBoard.ZobristHash();

    TestBoard.ParseFEN("rn1qk1nr/ppp2ppp/2bp1b2/4p3/3P4/2B1PB2/PPP2PPP/RN1QK1NR w KQkq - 0 1");

    int ZobristValue2 = TestBoard.ZobristHash();
    
    TestBoard.ParseFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

    int ZobristValue3 = TestBoard.ZobristHash();

    EXPECT_EQ(ZobristValue, ZobristValue3);

    EXPECT_NE(ZobristValue, ZobristValue2);
};
