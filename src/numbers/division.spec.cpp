#include "division.hpp"
#include <gtest/gtest.h>

using namespace funky;

TEST(Numerics, Factor) {
    EXPECT_TRUE(factor(10, 2));
    EXPECT_FALSE(factor(10, 3));
}

TEST(Numerics, Ratio) {
    EXPECT_EQ(ratio(10UL, 4.0), 2.5);
    EXPECT_EQ(ratio(10.0, 4UL), 2.5);
    EXPECT_EQ(ratio(10UL, 4UL), 2.5);
}
