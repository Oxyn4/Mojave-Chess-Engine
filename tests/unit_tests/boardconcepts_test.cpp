
#include <gtest/gtest.h>

#include "../../src/BoardConcepts.hpp"

TEST(boardconcepts_move, algerbraicnotation_generation) 
{
   Move TestMove(a2, a4, white, WhitePawn);

   EXPECT_EQ(TestMove.AlgerbraicNotation, "a2a4");
   
   Move TestMove2(c7, f5, white, WhitePawn);

   EXPECT_EQ(TestMove2.AlgerbraicNotation, "c7f5");

   Move TestMove3(d2, e8, white, WhitePawn);

   EXPECT_EQ(TestMove3.AlgerbraicNotation, "d2e8");

   Move TestMove4(g5, a4, white, WhitePawn);

   EXPECT_EQ(TestMove4.AlgerbraicNotation, "g5a4");

   Move TestMove5(e6, h8, white, WhitePawn);

   EXPECT_EQ(TestMove5.AlgerbraicNotation, "e6h8");

}

TEST(boardconcepts_move, algerbraicnotation_parsing) 
{
    Move TestMove("a2a4");

   EXPECT_EQ(TestMove.Origin, a2);
   EXPECT_EQ(TestMove.Destination, a4);
    
   Move TestMove2("h1b4");

   EXPECT_EQ(TestMove2.Origin, h1);
   EXPECT_EQ(TestMove2.Destination, b4);


    Move TestMove3("c4f7");

   EXPECT_EQ(TestMove3.Origin, c4);
   EXPECT_EQ(TestMove3.Destination, f7);


    Move TestMove4("d2e2");

   EXPECT_EQ(TestMove4.Origin, d2);
   EXPECT_EQ(TestMove4.Destination, e2);


    Move TestMove5("c6h1");

   EXPECT_EQ(TestMove5.Origin, c6);
   EXPECT_EQ(TestMove5.Destination, h1);
}
