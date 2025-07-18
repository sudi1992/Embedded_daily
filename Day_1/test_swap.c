#include <gtest/gtest.h>

#include "swap_utils.h"

TEST(SwapTest, BasicSwap) {
    int x = 5, y = 10;
    swap_xor(&x, &y);
    EXPECT_EQ(x, 10);
    EXPECT_EQ(y, 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
