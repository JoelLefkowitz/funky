#include "zip.tpp"
#include <deque>
#include <functional>
#include <gtest/gtest.h>
#include <vector>

using namespace funky;

TEST(Zip, Zip) {
    std::function<int(int, int)> sum = [](auto x, auto y) { return x + y; };

    EXPECT_EQ(zip(sum, std::vector<int>({1, 2, 3}), std::vector<int>({1, 2, 3})), std::vector<int>({2, 4, 6}));

    EXPECT_EQ(zip(sum, std::deque<int>({1, 2, 3}), std::deque<int>({1, 2, 3})), std::deque<int>({2, 4, 6}));
}
