#include "iterables.tpp"
#include "../concrete/numbers.hpp"
#include <cctype>
#include <cmath>
#include <deque>
#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace funky;

auto increment = [](auto x) {
    return x + 1;
};

auto even = [](auto x) {
    return funky::has_factor(x, 2);
};

auto add = [](auto x, auto y) {
    return x + y;
};

TEST(Iterables, Convert) {
    EXPECT_EQ(
        convert<std::deque<int>>(std::vector<int>({1, 2, 3})),
        std::deque<int>({1, 2, 3})
    );
}

TEST(Iterables, Reverse) {
    EXPECT_EQ(reverse(std::vector<int>({})), std::vector<int>({}));
    EXPECT_EQ(
        reverse(std::vector<int>({1, 2, 3})),
        std::vector<int>({3, 2, 1})
    );
}

TEST(Iterables, Map) {
    EXPECT_EQ(map(::toupper, "abc"), "ABC");

    EXPECT_EQ(
        map<std::vector<int>>(increment, std::vector<int>({1, 2, 3})),
        std::vector<int>({2, 3, 4})
    );

    EXPECT_EQ(
        map<std::vector<int>>(add, std::vector<int>({1, 2, 3})),
        std::vector<int>({1, 3, 5})
    );

    EXPECT_EQ(
        map<std::vector<int>>(add, std::vector<int>({1, 2, 3})),
        std::vector<int>({1, 3, 5})
    );
}

TEST(Iterables, Foreach) {
    auto total = 0;
    auto sum = [&total](auto x) {
        total += x;
    };

    // clang-format off
    foreach(sum, std::vector<int>({1, 2, 3}));
    // clang-format on
    EXPECT_EQ(total, 6);

    total = 0;

    auto sum_index = [&total](auto x, auto index) {
        total += x + index;
    };

    // clang-format off
    foreach(sum_index, std::vector<int>({1, 2, 3}));
    // clang-format on
    EXPECT_EQ(total, 9);
}

TEST(Iterables, Filter) {
    EXPECT_EQ(
        funky::filter(even, std::vector<int>({1, 2, 3, 4})),
        std::vector<int>({2, 4})
    );
}

TEST(Iterables, Fold) {
    EXPECT_EQ(fold(add, 0, std::vector<int>({1, 2, 3})), 6);
}

TEST(Iterables, Concat) {
    EXPECT_EQ(concat(std::vector<int>({}), 1), std::vector<int>({1}));
    EXPECT_EQ(concat(std::vector<int>({1}), 2), std::vector<int>({1, 2}));
    EXPECT_EQ(
        concat(std::vector<int>({1}), std::vector<int>({2, 3})),
        std::vector<int>({1, 2, 3})
    );
}

TEST(Iterables, Flatten) {
    EXPECT_EQ(flatten(std::vector<std::vector<int>>({})), std::vector<int>({}));
    EXPECT_EQ(
        flatten(std::vector<std::vector<int>>({
            {1, 2},
            {3, 4}
    })),
        std::vector<int>({1, 2, 3, 4})
    );
}

TEST(Iterables, Slice) {
    EXPECT_EQ(slice(std::vector<int>({1, 2, 3}), 0, 0), std::vector<int>({}));
    EXPECT_EQ(slice(std::vector<int>({1, 2, 3}), 0, 1), std::vector<int>({1}));
    EXPECT_EQ(slice(std::vector<int>({1, 2, 3}), 1, 1), std::vector<int>({}));
    EXPECT_EQ(
        slice(std::vector<int>({1, 2, 3}), 0, 2),
        std::vector<int>({1, 2})
    );
    EXPECT_EQ(
        slice(std::vector<int>({1, 2, 3}), 0, 3),
        std::vector<int>({1, 2, 3})
    );
    EXPECT_EQ(slice(std::vector<int>({1, 2, 3}), 1, 2), std::vector<int>({2}));
    EXPECT_EQ(slice(std::vector<int>({1, 2, 3}), 2, 1), std::vector<int>({}));
}

TEST(Iterables, SliceFirst) {
    EXPECT_EQ(
        slice_first(std::vector<int>({1, 2, 3}), 0),
        std::vector<int>({})
    );
    EXPECT_EQ(
        slice_first(std::vector<int>({1, 2, 3}), 1),
        std::vector<int>({1})
    );
    EXPECT_EQ(
        slice_first(std::vector<int>({1, 2, 3}), 2),
        std::vector<int>({1, 2})
    );
    EXPECT_EQ(
        slice_first(std::vector<int>({1, 2, 3}), 3),
        std::vector<int>({1, 2, 3})
    );
    EXPECT_EQ(
        slice_first(std::vector<int>({1, 2, 3}), 4),
        std::vector<int>({1, 2, 3})
    );
}

TEST(Iterables, SliceLast) {
    EXPECT_EQ(slice_last(std::vector<int>({1, 2, 3}), 0), std::vector<int>({}));
    EXPECT_EQ(
        slice_last(std::vector<int>({1, 2, 3}), 1),
        std::vector<int>({3})
    );
    EXPECT_EQ(
        slice_last(std::vector<int>({1, 2, 3}), 2),
        std::vector<int>({2, 3})
    );
    EXPECT_EQ(
        slice_last(std::vector<int>({1, 2, 3}), 3),
        std::vector<int>({1, 2, 3})
    );
    EXPECT_EQ(
        slice_last(std::vector<int>({1, 2, 3}), 4),
        std::vector<int>({1, 2, 3})
    );
}

TEST(Iterables, DropFirst) {
    EXPECT_EQ(drop_first(std::vector<int>({1, 2, 3}), 4), std::vector<int>({}));
    EXPECT_EQ(drop_first(std::vector<int>({1, 2, 3}), 3), std::vector<int>({}));
    EXPECT_EQ(
        drop_first(std::vector<int>({1, 2, 3}), 2),
        std::vector<int>({3})
    );
    EXPECT_EQ(
        drop_first(std::vector<int>({1, 2, 3}), 1),
        std::vector<int>({2, 3})
    );
    EXPECT_EQ(
        drop_first(std::vector<int>({1, 2, 3}), 0),
        std::vector<int>({1, 2, 3})
    );
}

TEST(Iterables, DropLast) {
    EXPECT_EQ(drop_last(std::vector<int>({1, 2, 3}), 4), std::vector<int>({}));
    EXPECT_EQ(drop_last(std::vector<int>({1, 2, 3}), 3), std::vector<int>({}));
    EXPECT_EQ(drop_last(std::vector<int>({1, 2, 3}), 2), std::vector<int>({1}));
    EXPECT_EQ(
        drop_last(std::vector<int>({1, 2, 3}), 1),
        std::vector<int>({1, 2})
    );
    EXPECT_EQ(
        drop_last(std::vector<int>({1, 2, 3}), 0),
        std::vector<int>({1, 2, 3})
    );
}

TEST(Iterables, Aperture) {
    std::vector<int> sequence({1, 2, 3, 4});
    EXPECT_EQ(aperture(sequence, 0), std::vector<std::vector<int>>({}));

    EXPECT_EQ(
        aperture(sequence, 1),
        std::vector<std::vector<int>>({{1}, {2}, {3}, {4}})
    );

    EXPECT_EQ(
        aperture(sequence, 2),
        std::vector<std::vector<int>>({
            {1, 2},
            {2, 3},
            {3, 4}
    })
    );

    EXPECT_EQ(
        aperture(sequence, 3),
        std::vector<std::vector<int>>({
            {1, 2, 3},
            {2, 3, 4}
    })
    );

    EXPECT_EQ(
        aperture(sequence, 4),
        std::vector<std::vector<int>>({
            {1, 2, 3, 4}
    })
    );
}
