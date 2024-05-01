#include "foreach.tpp"
#include <cstddef>
#include <deque>
#include <functional>
#include <gtest/gtest.h>
#include <vector>

using namespace functional;

TEST(Foreach, Foreach) {
    struct Number {
        int value;
    };

    Number number = {0};

    std::function<void(int)> add = [&number](auto x) { number.value += x; };

    // clang-format off
    foreach(add, std::vector<int>({1, 2, 3}));
    // clang-format on

    EXPECT_EQ(number.value, 6);

    // clang-format off
    foreach(add, std::deque<int>({1, 2, 3}));
    // clang-format on

    EXPECT_EQ(number.value, 12);
}

TEST(Functional, ZipForeach) {
    struct Number {
        int value;
    };

    Number number = {0};

    std::function<void(int, int)> add = [&number](auto x, auto y) { number.value += (x * y); };

    // clang-format off
    foreach(add, std::vector<int>({1, 2}), std::vector<int>({1, 2}));
    // clang-format on

    EXPECT_EQ(number.value, 5);
}

TEST(Functional, IndexedForeach) {
    struct Number {
        int value;
    };

    Number number = {0};

    std::function<void(int, size_t)> add = [&number](auto x, auto i) {
        auto index = static_cast<int>(i);
        number.value += (x * index);
    };

    // clang-format off
    foreach(add, std::vector<int>({1, 2, 3}));
    // clang-format on

    EXPECT_EQ(number.value, 8);
}
