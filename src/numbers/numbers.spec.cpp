#include "numbers.hpp"
#include <gtest/gtest.h>

using namespace funky;

TEST(Numerics, Frac) {
    EXPECT_NEAR(frac(1), 0, 0.001);
    EXPECT_NEAR(frac(1.1), 0.1, 0.001);
    EXPECT_NEAR(frac(-1.1), -0.1, 0.001);
}

TEST(Numerics, Round) {
    EXPECT_EQ(round(1.234, 0), 1);
    EXPECT_EQ(round(1.234, 1), 1.2);
    EXPECT_EQ(round(1.234, 2), 1.23);
    EXPECT_EQ(round(1.234, 3), 1.234);
    EXPECT_EQ(round(1.234, 4), 1.234);
}

TEST(Numerics, Sign) {
    EXPECT_EQ(sign(-2), -1);
    EXPECT_EQ(sign(-1), -1);
    EXPECT_EQ(sign(0), 0);
    EXPECT_EQ(sign(1), 1);
    EXPECT_EQ(sign(2), 1);
}

TEST(Numerics, Order) {
    EXPECT_EQ(order(1), 0);
    EXPECT_EQ(order(10), 1);
    EXPECT_EQ(order(100), 2);
    EXPECT_EQ(order(0.1), -1);
    EXPECT_EQ(order(0.01), -2);

    EXPECT_EQ(order(2), 0);
    EXPECT_EQ(order(20), 1);
    EXPECT_EQ(order(200), 2);
    EXPECT_EQ(order(0.2), -1);
    EXPECT_EQ(order(0.02), -2);

    EXPECT_EQ(order(0), 0);
    EXPECT_EQ(order(-1), 0);
    EXPECT_EQ(order(-10), 0);
    EXPECT_EQ(order(-0.1), 0);
}

TEST(Numerics, UnitsPrefix) {
    EXPECT_EQ(units_prefix(1), "");

    EXPECT_EQ(units_prefix(10), "⋅10");
    EXPECT_EQ(units_prefix(100), "⋅100");

    EXPECT_EQ(units_prefix(0.1), "÷10");
    EXPECT_EQ(units_prefix(0.01), "÷100");

    EXPECT_EQ(units_prefix(1000), "k");
    EXPECT_EQ(units_prefix(1000000), "M");
    EXPECT_EQ(units_prefix(0.001), "m");

    EXPECT_EQ(units_prefix(10000), "⋅10k");
    EXPECT_EQ(units_prefix(0.0001), "÷10m");

    EXPECT_EQ(units_prefix(200), "⋅100");
    EXPECT_EQ(units_prefix(2000), "k");

    EXPECT_EQ(units_prefix(0), "");
    EXPECT_EQ(units_prefix(-1), "");
    EXPECT_EQ(units_prefix(-100), "⋅100");
    EXPECT_EQ(units_prefix(-1000), "k");
}
