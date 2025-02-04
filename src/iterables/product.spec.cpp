#include "product.tpp"
#include <functional>
#include <gtest/gtest.h>
#include <utility>
#include <vector>

using namespace funky;

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
