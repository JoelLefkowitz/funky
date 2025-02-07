#include "callables.tpp"
#include <functional>
#include <gtest/gtest.h>

using namespace funky;

auto increment = [](auto x) {
    return x + 1;
};

TEST(Compose, Compose) {
    EXPECT_EQ(compose(increment, increment)(0), 2);
}

TEST(Pipe, Pipe) {
    EXPECT_EQ(pipe(0, increment, increment), 2);
}
