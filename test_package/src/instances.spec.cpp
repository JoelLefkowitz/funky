#include <cstddef>
#include <functional/instances/numbers/division.hpp>
#include <gtest/gtest.h>

TEST(Numbers, Ratio) { EXPECT_EQ(functional::ratio(1UL, 2UL), 0.5); }
