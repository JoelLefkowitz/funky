#include "fold.tpp"
#include <functional>
#include <gtest/gtest.h>
#include <vector>

using namespace funky;

auto sum = [](auto acc, auto x) {
    return acc + x;
};

TEST(Fold, Fold) {
    EXPECT_EQ(fold(sum, 0, std::vector<int>({1, 2, 3})), 6);
}
