#include "product.tpp"
#include <functional>
#include <gtest/gtest.h>
#include <vector>

using namespace funky;

TEST(Product, Product) {
    std::function<int(int, int)> sum = [](auto x, auto y) { return x + y; };
    EXPECT_EQ(product(sum, std::vector<int>({1, 2}), std::vector<int>({1, 2})), std::vector<int>({2, 3, 3, 4}));
}
