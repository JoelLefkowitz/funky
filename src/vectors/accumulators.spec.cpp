#include "accumulators.tpp"
#include <gtest/gtest.h>

using namespace funky;

TEST(Accumulators, Average) {
    EXPECT_EQ(average(std::vector<int>({1, 2, 3})), 2);
}
