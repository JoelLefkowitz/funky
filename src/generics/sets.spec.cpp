#include "sets.tpp"
#include "../concrete/numbers.hpp"
#include <cctype>
#include <cmath>
#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace funky;

auto even = [](auto x) {
    return has_factor(x, 2);
};

TEST(Sets, Contains) {
    EXPECT_TRUE(contains(std::vector<int>({1, 2, 3}), 1));

    EXPECT_FALSE(contains(std::vector<int>({}), 1));
    EXPECT_FALSE(contains(std::vector<int>({1}), 2));
}

TEST(Sets, IsUnique) {
    EXPECT_TRUE(is_unique(std::vector<int>({})));
    EXPECT_TRUE(is_unique(std::vector<int>({1})));

    EXPECT_FALSE(is_unique(std::vector<int>({1, 1})));
    EXPECT_FALSE(is_unique(std::vector<int>({1, 1, 2})));
}

TEST(Sets, Unique) {
    EXPECT_EQ(unique(std::vector<int>({})), std::vector<int>({}));
    EXPECT_EQ(unique(std::vector<int>({1, 2, 3})), std::vector<int>({1, 2, 3}));
    EXPECT_EQ(unique(std::vector<int>({1, 2, 2})), std::vector<int>({1, 2}));
}

TEST(Sets, Intersects) {
    EXPECT_TRUE(intersects(std::vector<int>({1}), std::vector<int>({1})));
    EXPECT_TRUE(intersects(std::vector<int>({1, 2}), std::vector<int>({2, 3})));

    EXPECT_FALSE(intersects(std::vector<int>({1, 2}), std::vector<int>({3, 4})));
    EXPECT_FALSE(intersects(std::vector<int>({}), std::vector<int>({1, 2})));
    EXPECT_FALSE(intersects(std::vector<int>({}), std::vector<int>({})));
}

TEST(Sets, Intersection) {
    EXPECT_EQ(intersection(std::vector<int>({1, 2, 3}), std::vector<int>({})), std::vector<int>({}));
    EXPECT_EQ(intersection(std::vector<int>({}), std::vector<int>({1, 2, 3})), std::vector<int>({}));

    EXPECT_EQ(intersection(std::vector<int>({1, 2}), std::vector<int>({2, 3})), std::vector<int>({2}));
    EXPECT_EQ(intersection(std::vector<int>({1, 2}), std::vector<int>({1, 2})), std::vector<int>({1, 2}));

    EXPECT_EQ(intersection(std::vector<int>({1, 1, 2}), std::vector<int>({1, 1, 2})), std::vector<int>({1, 2}));
}

TEST(Sets, Difference) {
    EXPECT_EQ(difference(std::vector<int>({1, 2, 3}), std::vector<int>({})), std::vector<int>({1, 2, 3}));
    EXPECT_EQ(difference(std::vector<int>({1, 2, 3}), std::vector<int>({2})), std::vector<int>({1, 3}));

    EXPECT_EQ(difference(std::vector<int>({1, 2, 3}), std::vector<int>({1, 2, 3})), std::vector<int>({}));
    EXPECT_EQ(difference(std::vector<int>({1, 2, 3}), std::vector<int>({1, 2, 3, 4})), std::vector<int>({}));

    EXPECT_EQ(difference(std::vector<int>({}), std::vector<int>({})), std::vector<int>({}));
    EXPECT_EQ(difference(std::vector<int>({}), std::vector<int>({1})), std::vector<int>({}));

    EXPECT_EQ(difference(std::vector<int>({1, 1, 2}), std::vector<int>({1, 1, 2})), std::vector<int>({}));
}

TEST(Sets, Index) {
    EXPECT_EQ(index(std::vector<int>({1, 2, 3}), 1), 0UL);
    EXPECT_EQ(index(std::vector<int>({1, 2, 3}), 2), 1UL);
    EXPECT_EQ(index(std::vector<int>({1, 2, 3}), 3), 2UL);
    EXPECT_EQ(index(std::vector<int>({1, 2, 3}), 4), 0UL);
}

TEST(Sets, Find) {
    EXPECT_EQ(find(even, std::vector<int>({1, 2, 3})), 1UL);
}

TEST(Sets, Min) {
    EXPECT_EQ(min(std::vector<int>({}), 0), 0);
    EXPECT_EQ(min(std::vector<int>({1}), 0), 1);
    EXPECT_EQ(min(std::vector<int>({1, 2}), 0), 1);
}

TEST(Sets, Max) {
    EXPECT_EQ(max(std::vector<int>({}), 0), 0);
    EXPECT_EQ(max(std::vector<int>({1}), 0), 1);
    EXPECT_EQ(max(std::vector<int>({1, 2}), 0), 2);
}
