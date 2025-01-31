#include "filter.tpp"
#include "../numbers/division.hpp"
#include <functional>
#include <gtest/gtest.h>
#include <vector>

using namespace funky;

TEST(Filter, Filter) {
    EXPECT_EQ(
        funky::filter([](auto x) { return funky::factor(x, 2); }, std::vector<int>({1, 2, 3, 4})),
        std::vector<int>({2, 4})
    );
}
