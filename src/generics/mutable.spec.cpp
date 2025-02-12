#include "mutable.tpp"
#include <cstddef>
#include <gtest/gtest.h>

using namespace funky;

auto even = [](auto x) {
    return has_factor(x, 2);
};

TEST(Mutable, Insert) {
    auto x = std::vector<int>({3, 4});
    auto y = std::vector<int>({1, 2});

    insert(x, y);

    EXPECT_EQ(x, std::vector<int>({3, 4}));
    EXPECT_EQ(y, std::vector<int>({1, 2, 3, 4}));
}

TEST(Mutable, Remove) {
    auto x = std::vector<int>({1, 2, 3, 2});

    remove(x, 2);

    EXPECT_EQ(x, std::vector<int>({1, 3}));
}

TEST(Mutable, Partition) {
    std::vector<int> sequence({1, 2, 3});

    partition(even, sequence);

    EXPECT_EQ(sequence, std::vector<int>({1, 3, 2}));
}
