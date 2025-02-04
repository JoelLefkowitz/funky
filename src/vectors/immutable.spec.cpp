#include "immutable.tpp"
#include <cstddef>
#include <gtest/gtest.h>

using namespace funky;

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
