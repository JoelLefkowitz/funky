#include "limits.tpp"
#include <gtest/gtest.h>

using namespace functional;

TEST(Numerics, Between) {
    EXPECT_TRUE(between(1, 2, 3));
    EXPECT_TRUE(between(1.0, 2.0, 3.0));

    EXPECT_FALSE(between(1, 4, 3));
    EXPECT_FALSE(between(1, 0, 3));

    EXPECT_FALSE(between(1, 1, 3));
    EXPECT_FALSE(between(1, 3, 3));
}

TEST(Numerics, Contains) {
    EXPECT_TRUE(contains(1, 2, 3));
    EXPECT_TRUE(contains(1.0, 2.0, 3.0));

    EXPECT_FALSE(contains(1, 4, 3));
    EXPECT_FALSE(contains(1, 0, 3));

    EXPECT_TRUE(contains(1, 1, 3));
    EXPECT_TRUE(contains(1, 3, 3));
}

TEST(Numerics, Clamp) {
    EXPECT_EQ(clamp(1, 2, 3), 2);
    EXPECT_EQ(clamp(1.0, 2.0, 3.0), 2.0);
    EXPECT_EQ(clamp(1, 4, 3), 3);
    EXPECT_EQ(clamp(1, 0, 3), 1);
}
