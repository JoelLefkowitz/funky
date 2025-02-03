#include "foreach.tpp"
#include <cstddef>
#include <gtest/gtest.h>
#include <vector>

using namespace funky;

TEST(Foreach, Foreach) {
    auto counter = 0;

    auto sum = [&counter](auto x) {
        counter += x;
    };

    // clang-format off
    foreach(sum, std::vector<int>({1, 2, 3}));
    // clang-format on
    EXPECT_EQ(counter, 6);
}

TEST(Functional, ZipForeach) {
    auto counter = 0;

    auto sum_products = [&counter](auto x, auto y) {
        counter += (x * y);
    };

    // clang-format off
    foreach(sum_products, std::vector<int>({1, 2}), std::vector<int>({1, 2}));
    // clang-format on

    EXPECT_EQ(counter, 5);
}

TEST(Functional, IndexedForeach) {
    auto counter = 0;

    auto sum_index_products = [&counter](auto x, auto i) {
        auto index = static_cast<int>(i);
        counter += (x * index);
    };

    // clang-format off
    foreach(sum_index_products, std::vector<int>({1, 2, 3}));
    // clang-format on

    EXPECT_EQ(counter, 8);
}
