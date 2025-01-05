#include "booleans.tpp"
#include "../numbers/division.hpp"
#include <functional>
#include <gtest/gtest.h>
#include <vector>

using namespace funky;

TEST(Booleans, All) {
    EXPECT_TRUE(all(std::vector<bool>({})));
    EXPECT_TRUE(all(std::vector<bool>({true})));
    EXPECT_TRUE(all(std::vector<bool>({true, true})));

    EXPECT_FALSE(all(std::vector<bool>({false})));
    EXPECT_FALSE(all(std::vector<bool>({true, false})));
    EXPECT_FALSE(all(std::vector<bool>({false, false})));

    std::function<bool(int)> even = [](auto x) { return factor(x, 2); };

    EXPECT_TRUE(all(even, std::vector<int>({})));
    EXPECT_TRUE(all(even, std::vector<int>({2, 4, 6})));

    EXPECT_FALSE(all(even, std::vector<int>({1, 2, 3})));
}

TEST(Booleans, Any) {
    EXPECT_TRUE(any(std::vector<bool>({true})));
    EXPECT_TRUE(any(std::vector<bool>({true, true})));
    EXPECT_TRUE(any(std::vector<bool>({true, false})));

    EXPECT_FALSE(any(std::vector<bool>({})));
    EXPECT_FALSE(any(std::vector<bool>({false})));
    EXPECT_FALSE(any(std::vector<bool>({false, false})));

    std::function<bool(int)> even = [](auto x) { return factor(x, 2); };

    EXPECT_TRUE(any(even, std::vector<int>({1, 2, 3})));

    EXPECT_FALSE(any(even, std::vector<int>({})));
    EXPECT_FALSE(any(even, std::vector<int>({1, 3, 5})));
}

TEST(Booleans, AtLeast) {
    EXPECT_TRUE(at_least(0, std::vector<bool>({})));
    EXPECT_TRUE(at_least(0, std::vector<bool>({true})));
    EXPECT_TRUE(at_least(1, std::vector<bool>({true})));
    EXPECT_TRUE(at_least(2, std::vector<bool>({true, true, false})));

    EXPECT_FALSE(at_least(1, std::vector<bool>({})));
    EXPECT_FALSE(at_least(1, std::vector<bool>({false})));
    EXPECT_FALSE(at_least(2, std::vector<bool>({true})));

    std::function<bool(int)> even = [](auto x) { return factor(x, 2); };

    EXPECT_TRUE(at_least(even, 1, std::vector<int>({1, 2, 3})));

    EXPECT_FALSE(at_least(even, 2, std::vector<int>({1, 3})));
}
