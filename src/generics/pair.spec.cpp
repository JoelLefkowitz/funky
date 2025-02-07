#include "pair.tpp"
#include <functional>
#include <gtest/gtest.h>
#include <utility>
#include <vector>

using namespace funky;

TEST(Pair, Pair) {
    std::vector<std::pair<int, int>> paired({
        {1, 2},
        {2, 3},
        {3, 4}
    });

    EXPECT_EQ(pairs(std::vector<int>({1, 2, 3, 4})), paired);
}

TEST(Product, Product) {
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

TEST(Zip, Zip) {
    std::vector<std::pair<int, int>> pairs({
        {1, 3},
        {2, 4}
    });

    EXPECT_EQ(zip(std::vector<int>({1, 2}), std::vector<int>({3, 4})), pairs);
}
