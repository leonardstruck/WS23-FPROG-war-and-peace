#include "doctest.h"
#include "../src/counter.h"

TEST_CASE("Count words") {
    std::vector<std::string> tokens = {"hello", "world", "hello", "world", "apples", "bananas", "apples", "oranges"};
    auto expected = counter::CountMap{
            {"hello",   2},
            {"world",   2},
            {"apples",  2},
            {"bananas", 1},
            {"oranges", 1}
    };

    auto result = counter::count_words(tokens);
    CHECK_EQ(result, expected);
}

TEST_CASE("Merge results") {
    auto map1 = counter::CountMap{
            {"hello",   2},
            {"world",   2},
            {"apples",  2},
            {"bananas", 1},
            {"oranges", 1}
    };

    auto map2 = counter::CountMap{
            {"hello",   1},
            {"world",   1},
            {"apples",  1},
            {"bananas", 2},
            {"oranges", 2}
    };

    auto expected = counter::CountMap{
            {"hello",   3},
            {"world",   3},
            {"apples",  3},
            {"bananas", 3},
            {"oranges", 3}
    };

    auto result = counter::merge_counts(map1, map2);
    CHECK_EQ(result, expected);
}

TEST_CASE("Count in parallel") {
    std::vector<std::string> tokens = {"hello", "world", "hello", "world", "apples", "bananas", "apples", "oranges"};
    auto expected = counter::CountMap{
            {"hello",   2},
            {"world",   2},
            {"apples",  2},
            {"bananas", 1},
            {"oranges", 1}
    };

    // set the chunk size to 1 so that each token is processed in parallel
    auto result = counter::count_words_parallel(tokens, 1);

    CHECK_EQ(result, expected);
}