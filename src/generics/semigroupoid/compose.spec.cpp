#include "compose.tpp"
#include <functional>
#include <gtest/gtest.h>

using namespace functional;

TEST(Compose, Compose) {
    std::function<int(int)> increment = [](auto x) { return x + 1; };
    EXPECT_EQ(compose(increment, increment)(0), 2);
}
