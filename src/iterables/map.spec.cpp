#include "map.tpp"
#include <cctype>
#include <cmath>
#include <functional>
#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace funky;

auto append = [](auto x, auto y) {
    return x + ": " + std::to_string(y);
};

auto increment = [](auto x) {
    return x + 1;
};

std::map<std::string, int> points({
    {"a", 1},
    {"b", 2}
});

TEST(Map, MapString) {
    EXPECT_EQ(map(::toupper, "abc"), "ABC");
}

TEST(Map, MapMap) {
    EXPECT_EQ(
        map<std::string>(append, points),
        std::vector<std::string>({"a: 1", "b: 2"})
    );
}

TEST(Map, Map) {
    EXPECT_EQ(
        map<std::vector<int>>(increment, std::vector<int>({1, 2})),
        std::vector<int>({2, 3})
    );
}
