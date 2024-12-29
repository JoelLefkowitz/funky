#include "pipe.tpp"
#include <functional>
#include <gtest/gtest.h>

using namespace funky;

TEST(Pipe, Pipe) {
    std::function<int(int)> increment = [](auto x) { return x + 1; };
    EXPECT_EQ(pipe(0, increment, increment), 2);
}
