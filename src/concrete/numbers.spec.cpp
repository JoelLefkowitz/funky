#include "numbers.tpp"
#include <gtest/gtest.h>

using namespace funky;

TEST(Numbers, Fractional) {
    EXPECT_NEAR(fractional(1), 0, 0.001);
    EXPECT_NEAR(fractional(1.1), 0.1, 0.001);
    EXPECT_NEAR(fractional(-1.1), -0.1, 0.001);
}

TEST(Numbers, Round) {
    EXPECT_EQ(round(1.234, 0), 1);
    EXPECT_EQ(round(1.234, 1), 1.2);
    EXPECT_EQ(round(1.234, 2), 1.23);
    EXPECT_EQ(round(1.234, 3), 1.234);
    EXPECT_EQ(round(1.234, 4), 1.234);
}

TEST(Numbers, Sign) {
    EXPECT_EQ(sign(-2), -1);
    EXPECT_EQ(sign(-1), -1);
    EXPECT_EQ(sign(0), 0);
    EXPECT_EQ(sign(1), 1);
    EXPECT_EQ(sign(2), 1);
}

TEST(Numbers, Order) {
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

TEST(Numbers, IsFactor) {
    EXPECT_TRUE(is_factor(2, 10));
    EXPECT_FALSE(is_factor(3, 10));
}

TEST(Numbers, HasFactor) {
    EXPECT_TRUE(has_factor(10, 2));
    EXPECT_FALSE(has_factor(10, 3));
}

TEST(Numbers, Ratio) {
    EXPECT_EQ(ratio(10UL, 4.0), 2.5);
    EXPECT_EQ(ratio(10.0, 4UL), 2.5);
    EXPECT_EQ(ratio(10UL, 4UL), 2.5);
}

TEST(Numbers, Unit) {
    EXPECT_EQ(unit(1, "m"), "m");
    EXPECT_EQ(unit(10, "m"), "⋅10m");
    EXPECT_EQ(unit(100, "m"), "⋅100m");
    EXPECT_EQ(unit(10000, "m"), "⋅10km");
    EXPECT_EQ(unit(1000, "m"), "km");
    EXPECT_EQ(unit(100000, "m"), "⋅100km");
    EXPECT_EQ(unit(1000000, "m"), "Mm");

    EXPECT_EQ(unit(0.1, "m"), "÷10m");
    EXPECT_EQ(unit(0.01, "m"), "÷100m");
    EXPECT_EQ(unit(0.001, "m"), "mm");
    EXPECT_EQ(unit(0.0001, "m"), "÷10mm");
    EXPECT_EQ(unit(0.00001, "m"), "÷100mm");
    EXPECT_EQ(unit(0.000001, "m"), "μm");

    EXPECT_EQ(unit(0, "m"), "m");
    EXPECT_EQ(unit(2, "m"), "m");
    EXPECT_EQ(unit(-1, "m"), "m");
}

TEST(Numbers, bounds) {
    EXPECT_TRUE(bounds(1, 2, 3));
    EXPECT_TRUE(bounds(1.0, 2.0, 3.0));

    EXPECT_FALSE(bounds(1, 4, 3));
    EXPECT_FALSE(bounds(1, 0, 3));

    EXPECT_FALSE(bounds(1, 1, 3));
    EXPECT_FALSE(bounds(1, 3, 3));
}

TEST(Numbers, includes) {
    EXPECT_TRUE(includes(1, 2, 3));
    EXPECT_TRUE(includes(1.0, 2.0, 3.0));

    EXPECT_FALSE(includes(1, 4, 3));
    EXPECT_FALSE(includes(1, 0, 3));

    EXPECT_TRUE(includes(1, 1, 3));
    EXPECT_TRUE(includes(1, 3, 3));
}

TEST(Numbers, Clamp) {
    EXPECT_EQ(clamp(1, 2, 3), 2);
    EXPECT_EQ(clamp(1.0, 2.0, 3.0), 2.0);
    EXPECT_EQ(clamp(1, 4, 3), 3);
    EXPECT_EQ(clamp(1, 0, 3), 1);
}
