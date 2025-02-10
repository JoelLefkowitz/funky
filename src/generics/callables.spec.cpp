#include "callables.tpp"
#include <gtest/gtest.h>

using namespace funky;

auto increment = [](auto x) {
    return x + 1;
};

TEST(Callables, Compose) {
    EXPECT_EQ(compose(increment, increment)(0), 2);
}

TEST(Callables, Pipe) {
    EXPECT_EQ(pipe(0, increment, increment), 2);
}
