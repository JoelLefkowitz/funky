#include "elements.tpp"
#include <cstddef>
#include <gtest/gtest.h>

using namespace funky;

TEST(Elements, Min) {
    EXPECT_EQ(min(std::vector<int>({})), 0);
    EXPECT_EQ(min(std::vector<int>({1})), 1);
    EXPECT_EQ(min(std::vector<int>({1, 2})), 1);
}

TEST(Elements, Max) {
    EXPECT_EQ(max(std::vector<int>({})), 0);
    EXPECT_EQ(max(std::vector<int>({1})), 1);
    EXPECT_EQ(max(std::vector<int>({1, 2})), 2);
}

TEST(Elements, Index) {
    EXPECT_EQ(index(std::vector<int>({1, 2, 3}), 1), 0UL);
    EXPECT_EQ(index(std::vector<int>({1, 2, 3}), 2), 1UL);
    EXPECT_EQ(index(std::vector<int>({1, 2, 3}), 3), 2UL);
    EXPECT_EQ(index(std::vector<int>({1, 2, 3}), 4), 0UL);

    std::function<bool(const std::string &)> single = [](const auto &x) { return x.size() == 1; };
    EXPECT_EQ(index(single, std::vector<std::string>({"aa", "b", "cc"})), 1UL);
}

TEST(Elements, Contains) {
    EXPECT_TRUE(contains(std::vector<int>({1, 2, 3}), 1));

    EXPECT_FALSE(contains(std::vector<int>({}), 1));
    EXPECT_FALSE(contains(std::vector<int>({1}), 2));
}

TEST(Elements, Repeats) {
    EXPECT_TRUE(repeats(std::vector<int>({1, 1})));
    EXPECT_TRUE(repeats(std::vector<int>({1, 1, 2})));

    EXPECT_FALSE(repeats(std::vector<int>({})));
    EXPECT_FALSE(repeats(std::vector<int>({1})));
}

TEST(Elements, Overlaps) {
    EXPECT_TRUE(overlaps(std::vector<int>({1}), std::vector<int>({1})));
    EXPECT_TRUE(overlaps(std::vector<int>({1, 2}), std::vector<int>({2, 3})));

    EXPECT_FALSE(overlaps(std::vector<int>({1, 2}), std::vector<int>({3, 4})));
    EXPECT_FALSE(overlaps(std::vector<int>({}), std::vector<int>({1, 2})));
    EXPECT_FALSE(overlaps(std::vector<int>({}), std::vector<int>({})));
}
