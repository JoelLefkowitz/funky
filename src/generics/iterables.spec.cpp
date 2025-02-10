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
    return funky::factor(x, 2);
};

auto sum = [](auto acc, auto x) {
    return acc + x;
};

auto append = [](auto x, auto y) {
    return x + ": " + std::to_string(y);
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

    std::map<std::string, int> points({
        {"a", 1},
        {"b", 2}
    });

    EXPECT_EQ(
        map<std::string>(append, points),
        std::vector<std::string>({"a: 1", "b: 2"})
    );

    EXPECT_EQ(
        map<std::vector<int>>(increment, std::vector<int>({1, 2})),
        std::vector<int>({2, 3})
    );

    std::vector<int> numbers({1, 2, 3});

    auto output = map<std::vector<int>>(increment, numbers);
}

TEST(Iterables, Foreach) {
    auto sum = 0;

    auto add = [&sum](auto x) {
        sum += x;
    };

    // clang-format off
    foreach(add, std::vector<int>({1, 2, 3}));
    // clang-format on
    EXPECT_EQ(sum, 6);

    auto products_sum = 0;

    auto add_products = [&products_sum](auto x, auto y) {
        products_sum += (x * y);
    };

    // clang-format off
    foreach(add_products, std::vector<int>({1, 2}), std::vector<int>({1, 2}));
    // clang-format on

    EXPECT_EQ(products_sum, 5);

    auto index_products_sum = 0;

    auto add_index_products = [&index_products_sum](auto x, auto i) {
        auto index = static_cast<int>(i);
        index_products_sum += (x * index);
    };

    // clang-format off
    foreach(add_index_products, std::vector<int>({1, 2, 3}));
    // clang-format on

    EXPECT_EQ(index_products_sum, 8);
}

TEST(Iterables, Filter) {
    EXPECT_EQ(
        funky::filter(even, std::vector<int>({1, 2, 3, 4})),
        std::vector<int>({2, 4})
    );
}

TEST(Iterables, Fold) {
    EXPECT_EQ(fold(sum, 0, std::vector<int>({1, 2, 3})), 6);
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
