#include "filter.tpp"
#include "../../implementations/numbers/division.hpp"
#include <deque>
#include <functional>
#include <gtest/gtest.h>
#include <vector>

using namespace functional;

TEST(Filter, Filter) {
    std::function<bool(int)> even = [](auto x) { return functional::factor(x, 2); };

    EXPECT_EQ(filter(even, std::vector<int>({})), std::vector<int>({}));
    EXPECT_EQ(filter(even, std::vector<int>({1, 2, 3, 4})), std::vector<int>({2, 4}));
}
