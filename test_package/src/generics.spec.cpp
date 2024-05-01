#include <functional/generics/functor/map.tpp>
#include <functional>
#include <gtest/gtest.h>
#include <vector>

TEST(Map, Map) {
    std::function<int(int)> increment = [](auto x) { return x + 1; };
    EXPECT_EQ(functional::map(increment, std::vector<int>({1, 2, 3})), std::vector<int>({2, 3, 4}));
}