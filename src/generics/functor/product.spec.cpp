#include "product.tpp"
#include <deque>
#include <functional>
#include <gtest/gtest.h>
#include <vector>

using namespace functional;

TEST(Product, Product) {
    std::function<int(int, int)> sum = [](auto x, auto y) { return x + y; };

    EXPECT_EQ(product(sum, std::vector<int>({1, 2}), std::vector<int>({1, 2})), std::vector<int>({2, 3, 3, 4}));

    EXPECT_EQ(product(sum, std::deque<int>({1, 2}), std::deque<int>({1, 2})), std::deque<int>({2, 3, 3, 4}));
}
