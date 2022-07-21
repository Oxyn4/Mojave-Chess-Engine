

#include <gtest/gtest.h>

#include "../src/Bitboard.hpp"

#include "../src/BoardConcepts.hpp"

// test the getbit function 
TEST(bitboard, getbit) 
{
    
    // declare a 64 bit int with all zeros except for second bit
    Bitboard GetBitTestBitboard = 0x4000000000000000;

    // get the 0th bit 
    int BitStatus = GetBit(&GetBitTestBitboard, h1);

    EXPECT_EQ(BitStatus, 0);

    // get first bit
    int SecondBitStatus = GetBit(&GetBitTestBitboard, g1);

    EXPECT_EQ(SecondBitStatus, 1);

};

TEST(bitboard, addbit) 
{
    Bitboard AddbitTestBitboard = 0x0;

    AddBit(&AddbitTestBitboard, g1);

    EXPECT_EQ(AddbitTestBitboard, 0x4000000000000000);


}

TEST(bitboard, delbit) 
{
    Bitboard DelBitTestBitboard = 0x4000000000000000;

    DelBit(&DelBitTestBitboard, g1);

    EXPECT_EQ(DelBitTestBitboard, 0x0);

}

int main(int argc, char* argv[]) 
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

