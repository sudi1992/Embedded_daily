#include <gtest/gtest.h>
#include "atoi_util.h"  // Include the header file for the atoi function


TEST(LibAtoiTest, HandlesPositiveNumbers) {
    EXPECT_EQ(libatoi("123"), 123);
    EXPECT_EQ(libatoi("   456"), 456);
}

TEST(LibAtoiTest, HandlesNegativeNumbers) {
    EXPECT_EQ(libatoi("-789"), -789);
    EXPECT_EQ(libatoi("   -42"), -42);
}

TEST(LibAtoiTest, HandlesZero) {
    EXPECT_EQ(libatoi("0"), 0);
    EXPECT_EQ(libatoi("   0"), 0);
}

TEST(LibAtoiTest, HandlesPlusSign) {
    EXPECT_EQ(libatoi("+321"), 321);
    EXPECT_EQ(libatoi("   +654"), 654);
}

TEST(LibAtoiTest, HandlesNonDigitCharacters) {
    EXPECT_EQ(libatoi("12abc34"), 12);
    EXPECT_EQ(libatoi("   -56xyz"), -56);
}

TEST(LibAtoiTest, HandlesEmptyString) {
    EXPECT_EQ(libatoi(""), 0);
    EXPECT_EQ(libatoi("   "), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}