#include "fold.tpp"
#include <deque>
#include <functional>
#include <gtest/gtest.h>
#include <vector>

using namespace functional;

TEST(Fold, Fold) {
    std::function<int(int, int)> sum = [](auto acc, auto x) { return acc + x; };
    EXPECT_EQ(fold(sum, 0, std::vector<int>({1, 2, 3})), 6);
    EXPECT_EQ(fold(sum, 0, std::deque<int>({1, 2, 3})), 6);
}
