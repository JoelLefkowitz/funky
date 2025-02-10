#include "pairs.tpp"
#include <gtest/gtest.h>
#include <utility>
#include <vector>

using namespace funky;

TEST(Pairs, Pair) {
    std::vector<std::pair<int, int>> paired({
        {1, 2},
        {2, 3},
        {3, 4}
    });

    EXPECT_EQ(pairs(std::vector<int>({1, 2, 3, 4})), paired);
}

TEST(Pairs, Product) {
    std::vector<std::pair<int, int>> pairs({
        {1, 3},
        {1, 4},
        {2, 3},
        {2, 4}
    });

    EXPECT_EQ(
        product(std::vector<int>({1, 2}), std::vector<int>({3, 4})),
        pairs
    );
}

TEST(Pairs, Zip) {
    std::vector<std::pair<int, int>> pairs({
        {1, 3},
        {2, 4}
    });

    EXPECT_EQ(zip(std::vector<int>({1, 2}), std::vector<int>({3, 4})), pairs);
}
