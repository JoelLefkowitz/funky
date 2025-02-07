#include "vectors.tpp"
#include <cstddef>
#include <gtest/gtest.h>
#include <utility>

using namespace funky;

TEST(Ranges, Range) {
    EXPECT_EQ(range(0), std::vector<size_t>({}));
    EXPECT_EQ(range(3), std::vector<size_t>({0, 1, 2}));

    EXPECT_EQ(range<int>(1, 4), std::vector<int>({1, 2, 3}));
    EXPECT_EQ(range<int>(1, 4, 1), std::vector<int>({1, 2, 3}));
    EXPECT_EQ(range<int>(1, 4, 2), std::vector<int>({1, 3}));

    EXPECT_EQ(range<double>(1, 2.5), std::vector<double>({1.0, 2.0}));
    EXPECT_EQ(range<double>(1, 2.5, 0.5), std::vector<double>({1.0, 1.5, 2.0}));
}

TEST(Ranges, Linspace) {
    EXPECT_EQ(linspace(0.0, 10.0, 0), std::vector<double>({}));
    EXPECT_EQ(linspace(0.0, 10.0, 1), std::vector<double>({0}));
    EXPECT_EQ(linspace(0.0, 10.0, 2), std::vector<double>({0, 10}));
    EXPECT_EQ(linspace(0.0, 10.0, 3), std::vector<double>({0, 5, 10}));

    EXPECT_EQ(
        linspace(0.0, 10.0, 5),
        std::vector<double>({0, 2.5, 5, 7.5, 10})
    );

    EXPECT_EQ(linspace(1.0, 10.0, 4), std::vector<double>({1, 4, 7, 10}));
}

TEST(Ranges, Enumerate) {
    std::vector<std::pair<size_t, int>> pairs({
        {0, 2},
        {1, 4},
        {2, 6}
    });

    EXPECT_EQ(enumerate(std::vector<int>({2, 4, 6})), pairs);
}
