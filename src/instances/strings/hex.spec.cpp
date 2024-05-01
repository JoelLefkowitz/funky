#include "hex.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace functional;

TEST(Hex, Hex) {
    EXPECT_EQ(hex(0), "0");
    EXPECT_EQ(hex(0, 2), "00");

    EXPECT_EQ(hex(10), "a");
    EXPECT_EQ(hex(100), "64");

    EXPECT_EQ(hex(100, 1), "64");
    EXPECT_EQ(hex(100, 2), "64");
    EXPECT_EQ(hex(100, 3), "064");
}

TEST(Hex, ParseHex) {
    EXPECT_EQ(parse_hex("0"), 0);
    EXPECT_EQ(parse_hex("a"), 10);
    EXPECT_EQ(parse_hex("A"), 10);
    EXPECT_EQ(parse_hex("64"), 100);
}
