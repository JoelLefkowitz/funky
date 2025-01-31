#include "foreach.tpp"
#include <cstddef>
#include <gtest/gtest.h>
#include <vector>

using namespace funky;

struct Number {
    int value;
};

TEST(Foreach, Foreach) {
    Number number = {0};

    // clang-format off
    foreach([&number](auto x) { number.value += x; }, std::vector<int>({1, 2, 3}));
    // clang-format on

    EXPECT_EQ(number.value, 6);
}

TEST(Functional, ZipForeach) {
    Number number = {0};

    // clang-format off
    foreach(
        [&number](auto x, auto y) { number.value += (x * y); },
        std::vector<int>({1, 2}),
        std::vector<int>({1, 2})
    );
    // clang-format on

    EXPECT_EQ(number.value, 5);
}

TEST(Functional, IndexedForeach) {
    Number number = {0};

    // clang-format off
    foreach(
        [&number](auto x, auto i) {
            auto index = static_cast<int>(i);
            number.value += (x * index);
        },
        std::vector<int>({1, 2, 3})
    );
    // clang-format on

    EXPECT_EQ(number.value, 8);
}
