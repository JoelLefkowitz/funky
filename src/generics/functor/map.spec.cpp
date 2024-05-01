#include "map.tpp"
#include <cmath>
#include <deque>
#include <functional>
#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace functional;

TEST(Map, Map) {
    std::function<int(int)>    increment = [](auto x) { return x + 1; };
    std::function<int(double)> round     = [](auto x) { return std::round(x); };

    EXPECT_EQ(map(increment, std::vector<int>({})), std::vector<int>({}));
    EXPECT_EQ(map(increment, std::deque<int>({})), std::deque<int>({}));

    EXPECT_EQ(map(increment, std::vector<int>({1, 2})), std::vector<int>({2, 3}));
    EXPECT_EQ(map(increment, std::deque<int>({1, 2})), std::deque<int>({2, 3}));

    EXPECT_EQ(map(round, std::vector<double>({1.0, 2.0})), std::vector<int>({1, 2}));
    EXPECT_EQ(map(round, std::deque<double>({1.0, 2.0})), std::deque<int>({1, 2}));
}

TEST(Map, MapString) {
    std::function<int(const std::string &)> length = [](const auto &x) { return x.length(); };

    std::function<char(char)> upper = [](auto x) { return toupper(x); };

    EXPECT_EQ(map(length, std::vector<std::string>({"a", "b"})), std::vector<int>({1, 1}));
    EXPECT_EQ(map(length, std::deque<std::string>({"a", "b"})), std::deque<int>({1, 1}));

    EXPECT_EQ(map(upper, "abc"), "ABC");
}

TEST(Map, MapMap) {
    std::function<std::string(const std::string &, const std::string &)> join = [](const auto &x, const auto &y) {
        return x + y;
    };

    std::map<std::string, std::string> capitals({
        {"a", "A"},
        {"b", "B"}
    });

    EXPECT_EQ(map(join, capitals), std::vector<std::string>({"aA", "bB"}));
}
