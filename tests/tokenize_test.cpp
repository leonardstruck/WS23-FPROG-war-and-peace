#include "doctest.h"
#include "../src/tokenize.hpp"

TEST_CASE("replace punctuation with spaces") {
std::string input = "Hello, World!";
std::string expected = "Hello  World ";
std::string actual = input | replace_punctuation_with_spaces | to_string;
CHECK(actual == expected);
}

TEST_CASE("replace non-printable characters with spaces") {
std::string input = "Hello,\nWorld!";
std::string expected = "Hello, World!";
std::string actual = input | replace_non_printable_characters_with_spaces | to_string;
CHECK(actual == expected);
}

TEST_CASE("sanitize") {
std::string input = "Hello,\nWorld!";
std::string expected = "hello  world ";
std::string actual = input | sanitize | to_string;
CHECK(actual == expected);
}

TEST_CASE("tokenize") {
    std::string input = "Hello,\nWorld!";
    std::vector<std::string> expected = {"hello", "world"};
    auto actual = tokenize(input);
    CHECK(actual == expected);
}
