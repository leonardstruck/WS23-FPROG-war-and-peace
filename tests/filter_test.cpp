#include "doctest.h"
#include "../src/filter.h"

TEST_CASE("Testing create_set function") {
    std::vector<std::string> words = {"apple", "banana", "cherry"};
    auto wordSet = filter::create_set(words);

    CHECK(wordSet.contains("apple"));
    CHECK(wordSet.contains("banana"));
    CHECK(wordSet.contains("cherry"));
    CHECK(!wordSet.contains("orange"));
}

TEST_CASE("Testing create_set_pluralized function") {
    std::vector<std::string> words = {"apple", "banana"};
    auto wordSet = filter::create_set_pluralized(words);

    CHECK(wordSet.contains("apples"));
    CHECK(wordSet.contains("bananas"));
    CHECK(!wordSet.contains("apple"));
    CHECK(!wordSet.contains("banana"));
}

TEST_CASE("filter_predicate") {
    auto filter_set = std::unordered_set<std::string>{"apple", "banana"};
    auto filter_set_pluralized = std::unordered_set<std::string>{"apples", "bananas"};

    CHECK(filter::filter_predicate(filter_set, filter_set_pluralized, "apple"));
    CHECK(filter::filter_predicate(filter_set, filter_set_pluralized, "bananas"));
    CHECK_FALSE(filter::filter_predicate(filter_set, filter_set_pluralized, "cherry"));
}

TEST_CASE("filter_word") {
    std::vector<std::string> filter = {"apple", "banana"};
    CHECK(filter::filter_word("apple", filter));
    CHECK(filter::filter_word("bananas", filter));
    CHECK_FALSE(filter::filter_word("cherry", filter));
}


TEST_CASE("Testing filter_words function") {
    std::vector<std::string> words = {"apple", "bananas", "cherry", "grapes"};
    std::vector<std::string> filter = {"banana", "grape"};

    auto filteredWords = filter::filter_words(words, filter);

    // Should contain "bananas" and "grapes", but not "apple" or "cherry"
    CHECK(std::find(filteredWords.begin(), filteredWords.end(), "bananas") != filteredWords.end());
    CHECK(std::find(filteredWords.begin(), filteredWords.end(), "grapes") != filteredWords.end());
    CHECK(std::find(filteredWords.begin(), filteredWords.end(), "apple") == filteredWords.end());
    CHECK(std::find(filteredWords.begin(), filteredWords.end(), "cherry") == filteredWords.end());
}