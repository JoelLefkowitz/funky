#include "pair.tpp"
#include <functional>
#include <gtest/gtest.h>
#include <utility>
#include <vector>

using namespace funky;

TEST(Pair, Pair) {
    std::vector<std::pair<int, int>> pairs({
        {1, 2},
        {2, 3},
        {3, 4}
    });

    EXPECT_EQ(::pair(std::vector<int>({1, 2, 3, 4})), pairs);
}
