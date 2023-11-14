#include "doctest.h"
#include "../src/tokenizer.cpp"

using namespace tokenizer;

TEST_CASE("replace punctuation with spaces") {
    SUBCASE("Empty String") {
        std::string input;
        std::string expected;
        auto result = input | replace_punctuation_with_spaces | to_string;
        CHECK_EQ(result, expected);
    }

    SUBCASE("String without Punctuation") {
        std::string input = "Hello World";
        std::string expected = "Hello World";
        auto result = input | replace_punctuation_with_spaces | to_string;
        CHECK_EQ(result, expected);
    }

    SUBCASE("String with Multiple Punctuation Marks") {
        std::string input = "Hello, World!";
        std::string expected = "Hello  World ";
        auto result = input | replace_punctuation_with_spaces | to_string;
        CHECK_EQ(result, expected);
    }

    SUBCASE("String with Only Punctuation") {
        std::string input = "!,.";
        std::string expected = "   ";
        auto result = input | replace_punctuation_with_spaces | to_string;
        CHECK_EQ(result, expected);
    }
}

TEST_CASE("replace non-printable characters with spaces") {
    SUBCASE("Empty String") {
        std::string input;
        std::string expected;
        auto result = input | replace_non_printable_characters_with_spaces | to_string;
        CHECK_EQ(result, expected);
    }

    SUBCASE("String without Non-Printable Characters") {
        std::string input = "Hello World";
        std::string expected = "Hello World";
        auto result = input | replace_non_printable_characters_with_spaces | to_string;
        CHECK_EQ(result, expected);
    }

    SUBCASE("String with Multiple Non-Printable Characters") {
        std::string input = "Hello\n\tWorld";
        std::string expected = "Hello  World";
        auto result = input | replace_non_printable_characters_with_spaces | to_string;
        CHECK_EQ(result, expected);
    }

    SUBCASE("String with Only Non-Printable Characters") {
        std::string input = "\n\t";
        std::string expected = "  ";
        auto result = input | replace_non_printable_characters_with_spaces | to_string;
        CHECK_EQ(result, expected);
    }
}

TEST_CASE("sanitize") {
    SUBCASE("Combination of Punctuation and Non-Printable Characters") {
        std::string input = "Hello,\nWorld!";
        std::string expected = "hello  world ";
        auto result = input | sanitize | to_string;
        CHECK_EQ(result, expected);
    }

    SUBCASE("Case Sensitivity") {
        std::string input = "HeLLo, WoRLD!";
        std::string expected = "hello  world ";
        auto result = input | sanitize | to_string;
        CHECK_EQ(result, expected);
    }

    SUBCASE("Strings with Numerical Values") {
        std::string input = "H3llo, W0rld!";
        std::string expected = "h3llo  w0rld ";
        auto result = input | sanitize | to_string;
        CHECK_EQ(result, expected);
    }
}

TEST_CASE("tokenize") {
    SUBCASE("String with Various Delimiters") {
        std::string input = "Hello, World! This-is a test.";
        std::vector<std::string> expected = {"hello", "world", "this", "is", "a", "test"};
        auto result = tokenize(input);
        CHECK_EQ(result, expected);
    }

    SUBCASE("Repeated Delimiters") {
        std::string input = "Hello  World  This  is  a  test";
        std::vector<std::string> expected = {"hello", "world", "this", "is", "a", "test"};
        auto result = tokenize(input);
        CHECK_EQ(result, expected);
    }

    SUBCASE("Case Sensitivity") {
        std::string input = "Hello, WORLD!";
        std::vector<std::string> expected = {"hello", "world"};
        auto result = tokenize(input);
        CHECK_EQ(result, expected);
    }
}
