#include "pair.tpp"
#include <functional>
#include <gtest/gtest.h>
#include <vector>

using namespace funky;

TEST(Pair, Pair) {
    std::function<int(int, int)> sum = [](auto x, auto y) { return x + y; };
    EXPECT_TRUE(::pair(sum, std::vector<int>({1})).empty());
    EXPECT_EQ(::pair(sum, std::vector<int>({1, 2})), std::vector<int>({3}));
    EXPECT_EQ(::pair(sum, std::vector<int>({1, 2, 3})), std::vector<int>({3, 5}));
}
