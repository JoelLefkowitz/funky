#include "strings.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace funky;

TEST(Strings, ReverseCopy) {
    std::string str = "abc";

    EXPECT_EQ(reverse_copy(str), "cba");
    EXPECT_EQ(str, "abc");
}

TEST(Strings, Pad) {
    std::string str = "abc";

    EXPECT_EQ(pad(str, 2), "abc");
    EXPECT_EQ(pad(str, 3), "abc");
    EXPECT_EQ(pad(str, 4), "abc ");
    EXPECT_EQ(pad(str, 5), "abc  ");
}

TEST(Strings, Chunk) {
    EXPECT_EQ(chunk("abcd", 0), std::vector<std::string>({}));
    EXPECT_EQ(chunk("abcd", 1), std::vector<std::string>({"a", "b", "c", "d"}));
    EXPECT_EQ(chunk("abcd", 2), std::vector<std::string>({"ab", "cd"}));

    EXPECT_EQ(chunk("abcd", 3), std::vector<std::string>({"abc"}));
    EXPECT_EQ(chunk("abcd", 4), std::vector<std::string>({"abcd"}));
    EXPECT_EQ(chunk("abcd", 5), std::vector<std::string>({}));

    EXPECT_EQ(chunk("", 0), std::vector<std::string>({}));
    EXPECT_EQ(chunk("", 1), std::vector<std::string>({}));
}

TEST(Strings, Split) {
    EXPECT_EQ(split("", "-"), std::vector<std::string>({""}));
    EXPECT_EQ(split("abc", ""), std::vector<std::string>({"a", "b", "c"}));

    EXPECT_EQ(split("a-a", "-"), std::vector<std::string>({"a", "a"}));
    EXPECT_EQ(split("a-a-a", "-"), std::vector<std::string>({"a", "a", "a"}));
    EXPECT_EQ(
        split("ab-a-ab", "-"),
        std::vector<std::string>({"ab", "a", "ab"})
    );
}

TEST(Strings, StartsWith) {
    EXPECT_TRUE(starts_with("abc", ""));
    EXPECT_TRUE(starts_with("abc", "a"));
    EXPECT_TRUE(starts_with("abc", "ab"));
    EXPECT_TRUE(starts_with("abc", "abc"));

    EXPECT_FALSE(starts_with("", "a"));
    EXPECT_FALSE(starts_with("abc", "b"));
    EXPECT_FALSE(starts_with("abc", "abc_"));
}

TEST(Strings, EndsWith) {
    EXPECT_TRUE(ends_with("abc", ""));
    EXPECT_TRUE(ends_with("abc", "c"));
    EXPECT_TRUE(ends_with("abc", "bc"));
    EXPECT_TRUE(ends_with("abc", "abc"));

    EXPECT_FALSE(ends_with("", "a"));
    EXPECT_FALSE(ends_with("abc", "b"));
    EXPECT_FALSE(ends_with("abc", "_abc"));
}

TEST(Strings, Uppercase) {
    EXPECT_EQ(uppercase(""), "");
    EXPECT_EQ(uppercase("a"), "A");
    EXPECT_EQ(uppercase("abc"), "ABC");
}

TEST(Strings, Lowercase) {
    EXPECT_EQ(lowercase(""), "");
    EXPECT_EQ(lowercase("A"), "a");
    EXPECT_EQ(lowercase("ABC"), "abc");
}

TEST(Strings, Truncate) {
    EXPECT_EQ(funky::truncate("abcdef", 0), "...");
    EXPECT_EQ(funky::truncate("abcdef", 1), "...");
    EXPECT_EQ(funky::truncate("abcdef", 2), "...");
    EXPECT_EQ(funky::truncate("abcdef", 3), "...");
    EXPECT_EQ(funky::truncate("abcdef", 4), "a...");
    EXPECT_EQ(funky::truncate("abcdef", 5), "ab...");
    EXPECT_EQ(funky::truncate("abcdef", 6), "abcdef");
}

TEST(Strings, Join) {
    EXPECT_EQ(join({}, ""), "");
    EXPECT_EQ(join({"a"}, ""), "a");
    EXPECT_EQ(join({"a", "b"}, ""), "ab");
    EXPECT_EQ(join({"a", "b", "c"}, ""), "abc");

    EXPECT_EQ(join({}, ","), "");
    EXPECT_EQ(join({"a"}, ","), "a");
    EXPECT_EQ(join({"a", "b"}, ","), "a,b");
    EXPECT_EQ(join({"a", "b", "c"}, ","), "a,b,c");
}

TEST(Strings, RemoveSubstrings) {
    EXPECT_EQ(remove_substrings("a-b", {"-"}), "ab");
    EXPECT_EQ(remove_substrings("a---b", {"-"}), "ab");

    EXPECT_EQ(remove_substrings("abc-abc-abc", {"b"}), "ac-ac-ac");
    EXPECT_EQ(remove_substrings("a-a-a-a-a", {"a-a"}), "--a");

    EXPECT_EQ(remove_substrings("abc-abc", {"a", "b"}), "c-c");
    EXPECT_EQ(remove_substrings("a-b-b-b-c", {"-", "b"}), "ac");
}
