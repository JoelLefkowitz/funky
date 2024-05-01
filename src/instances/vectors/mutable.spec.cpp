#include "mutable.tpp"
#include <cstddef>
#include <gtest/gtest.h>

using namespace functional;

TEST(Mutable, Insert) {
    auto x = std::vector<int>({3, 4});
    auto y = std::vector<int>({1, 2});

    insert(x, y);

    EXPECT_EQ(x, std::vector<int>({3, 4}));
    EXPECT_EQ(y, std::vector<int>({1, 2, 3, 4}));
}

TEST(Mutable, Erase) {
    auto x = std::vector<int>({1, 2, 2, 3});

    erase(x, 2);

    EXPECT_EQ(x, std::vector<int>({1, 3}));
}

TEST(Mutable, MoveToBack) {
    std::vector<int> sequence({1, 2, 3});

    std::function<bool(int)> filter = [](auto x) { return x == 2; };

    move_to_back(filter, sequence);
    EXPECT_EQ(sequence, std::vector<int>({1, 3, 2}));
}
