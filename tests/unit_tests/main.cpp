
#include <gtest/gtest.h>

/*
    run all GTEST unit tests if pass run benchmarka
 
*/
int main(int argc, char* argv[]) 
{
    testing::InitGoogleTest(&argc, argv);
    
    // run all unit tests 
    return RUN_ALL_TESTS();
}


