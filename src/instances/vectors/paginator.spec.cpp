#include "paginator.tpp"
#include "elements.hpp"
#include "immutable.hpp"
#include "mutable.hpp"
#include "ranges.hpp"
#include <cstddef>
#include <gtest/gtest.h>
#include <numeric>

using namespace functional;

TEST(Paginator, Pages) {
    auto ints = functional::range(8);

    Paginator<size_t> paginator(ints, 3);
    EXPECT_EQ(paginator.current(), std::vector<size_t>({0, 1, 2}));
    EXPECT_TRUE(paginator.first());
    EXPECT_FALSE(paginator.last());

    paginator.previous();
    EXPECT_EQ(paginator.current(), std::vector<size_t>({0, 1, 2}));
    EXPECT_TRUE(paginator.first());
    EXPECT_FALSE(paginator.last());

    paginator.next();
    EXPECT_EQ(paginator.current(), std::vector<size_t>({3, 4, 5}));
    EXPECT_FALSE(paginator.first());
    EXPECT_FALSE(paginator.last());

    paginator.next();
    EXPECT_EQ(paginator.current(), std::vector<size_t>({6, 7}));
    EXPECT_FALSE(paginator.first());
    EXPECT_TRUE(paginator.last());

    paginator.next();
    EXPECT_EQ(paginator.current(), std::vector<size_t>({6, 7}));
    EXPECT_FALSE(paginator.first());
    EXPECT_TRUE(paginator.last());
}
