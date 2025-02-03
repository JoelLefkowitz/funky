#include "compose.tpp"
#include <functional>
#include <gtest/gtest.h>

using namespace funky;

auto increment = [](auto x) {
    return x + 1;
};

TEST(Compose, Compose) {
    EXPECT_EQ(compose(increment, increment)(0), 2);
}
