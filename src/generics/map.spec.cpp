#include "map.tpp"
#include "../concrete/numbers.hpp"
#include <cctype>
#include <cmath>
#include <functional>
#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace funky;

auto append = [](auto x, auto y) {
    return x + ": " + std::to_string(y);
};

auto increment = [](auto x) {
    return x + 1;
};

auto even = [](auto x) {
    return funky::factor(x, 2);
};

auto sum = [](auto acc, auto x) {
    return acc + x;
};

std::map<std::string, int> points({
    {"a", 1},
    {"b", 2}
});

TEST(Map, MapString) {
    EXPECT_EQ(map(::toupper, "abc"), "ABC");
}

TEST(Map, MapMap) {
    EXPECT_EQ(
        map<std::string>(append, points),
        std::vector<std::string>({"a: 1", "b: 2"})
    );
}

TEST(Map, Map) {
    EXPECT_EQ(
        map<std::vector<int>>(increment, std::vector<int>({1, 2})),
        std::vector<int>({2, 3})
    );

    std::vector<int> numbers({1, 2, 3});

    auto output = map<std::vector<int>>(
        [](auto x) {
            return x + 1;
        },
        numbers
    );
}

TEST(Foreach, Foreach) {
    auto counter = 0;

    auto sum = [&counter](auto x) {
        counter += x;
    };

    // clang-format off
    foreach(sum, std::vector<int>({1, 2, 3}));
    // clang-format on
    EXPECT_EQ(counter, 6);
}

TEST(Functional, ZipForeach) {
    auto counter = 0;

    auto sum_products = [&counter](auto x, auto y) {
        counter += (x * y);
    };

    // clang-format off
    foreach(sum_products, std::vector<int>({1, 2}), std::vector<int>({1, 2}));
    // clang-format on

    EXPECT_EQ(counter, 5);
}

TEST(Functional, IndexedForeach) {
    auto counter = 0;

    auto sum_index_products = [&counter](auto x, auto i) {
        auto index = static_cast<int>(i);
        counter += (x * index);
    };

    // clang-format off
    foreach(sum_index_products, std::vector<int>({1, 2, 3}));
    // clang-format on

    EXPECT_EQ(counter, 8);
}

TEST(Filter, Filter) {
    EXPECT_EQ(
        funky::filter(even, std::vector<int>({1, 2, 3, 4})),
        std::vector<int>({2, 4})
    );
}

TEST(Fold, Fold) {
    EXPECT_EQ(fold(sum, 0, std::vector<int>({1, 2, 3})), 6);
}

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

    std::function<bool(const std::string &)> single = [](const auto &x) {
        return x.size() == 1;
    };
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

TEST(Immutable, Unique) {
    EXPECT_EQ(unique(std::vector<int>({})), std::vector<int>({}));
    EXPECT_EQ(unique(std::vector<int>({1, 2, 3})), std::vector<int>({1, 2, 3}));
    EXPECT_EQ(unique(std::vector<int>({1, 2, 2})), std::vector<int>({1, 2}));
}

TEST(Immutable, Reverse) {
    EXPECT_EQ(reverse(std::vector<int>({})), std::vector<int>({}));
    EXPECT_EQ(
        reverse(std::vector<int>({1, 2, 3})),
        std::vector<int>({3, 2, 1})
    );
}

TEST(Immutable, Difference) {
    EXPECT_EQ(
        difference(std::vector<int>({1, 2, 3}), std::vector<int>({})),
        std::vector<int>({1, 2, 3})
    );
    EXPECT_EQ(
        difference(std::vector<int>({1, 2, 3}), std::vector<int>({2})),
        std::vector<int>({1, 3})
    );

    EXPECT_EQ(
        difference(std::vector<int>({1, 2, 3}), std::vector<int>({1, 2, 3})),
        std::vector<int>({})
    );
    EXPECT_EQ(
        difference(std::vector<int>({1, 2, 3}), std::vector<int>({1, 2, 3, 4})),
        std::vector<int>({})
    );

    EXPECT_EQ(
        difference(std::vector<int>({}), std::vector<int>({})),
        std::vector<int>({})
    );
    EXPECT_EQ(
        difference(std::vector<int>({}), std::vector<int>({1})),
        std::vector<int>({})
    );

    EXPECT_EQ(
        difference(std::vector<int>({1, 1, 2}), std::vector<int>({1, 1, 2})),
        std::vector<int>({})
    );
}

TEST(Immutable, Intersection) {
    EXPECT_EQ(
        intersection(std::vector<int>({1, 2, 3}), std::vector<int>({})),
        std::vector<int>({})
    );
    EXPECT_EQ(
        intersection(std::vector<int>({}), std::vector<int>({1, 2, 3})),
        std::vector<int>({})
    );

    EXPECT_EQ(
        intersection(std::vector<int>({1, 2}), std::vector<int>({2, 3})),
        std::vector<int>({2})
    );
    EXPECT_EQ(
        intersection(std::vector<int>({1, 2}), std::vector<int>({1, 2})),
        std::vector<int>({1, 2})
    );

    EXPECT_EQ(
        intersection(std::vector<int>({1, 1, 2}), std::vector<int>({1, 1, 2})),
        std::vector<int>({1, 2})
    );
}

TEST(Immutable, Slice) {
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

TEST(Immutable, SliceFirst) {
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

TEST(Immutable, SliceLast) {
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

TEST(Immutable, DropFirst) {
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

TEST(Immutable, DropLast) {
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

TEST(Immutable, Aperture) {
    std::vector<std::vector<int>> slides({});
    EXPECT_EQ(aperture(std::vector<int>({1, 2, 3, 4}), 0), slides);

    slides = std::vector<std::vector<int>>({
        {1},
        {2},
        {3},
        {4},
    });
    EXPECT_EQ(aperture(std::vector<int>({1, 2, 3, 4}), 1), slides);

    slides = std::vector<std::vector<int>>({
        {1, 2},
        {2, 3},
        {3, 4},
    });
    EXPECT_EQ(aperture(std::vector<int>({1, 2, 3, 4}), 2), slides);

    slides = std::vector<std::vector<int>>({
        {1, 2, 3},
        {2, 3, 4},
    });
    EXPECT_EQ(aperture(std::vector<int>({1, 2, 3, 4}), 3), slides);

    slides = std::vector<std::vector<int>>({
        {1, 2, 3, 4},
    });
    EXPECT_EQ(aperture(std::vector<int>({1, 2, 3, 4}), 4), slides);
}

TEST(Immutable, Concat) {
    EXPECT_EQ(concat(std::vector<int>({}), 1), std::vector<int>({1}));
    EXPECT_EQ(concat(std::vector<int>({1}), 2), std::vector<int>({1, 2}));
    EXPECT_EQ(
        concat(std::vector<int>({1}), std::vector<int>({2, 3})),
        std::vector<int>({1, 2, 3})
    );
}

TEST(Immutable, Flatten) {
    EXPECT_EQ(flatten(std::vector<std::vector<int>>({})), std::vector<int>({}));
    EXPECT_EQ(
        flatten(std::vector<std::vector<int>>({
            {1, 2},
            {3, 4}
    })),
        std::vector<int>({1, 2, 3, 4})
    );
}
