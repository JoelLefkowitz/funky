#include "fold.tpp"
#include <functional>
#include <gtest/gtest.h>
#include <vector>

using namespace funky;

TEST(Fold, Fold) {
    EXPECT_EQ(fold([](auto acc, auto x) { return acc + x; }, 0, std::vector<int>({1, 2, 3})), 6);
}
