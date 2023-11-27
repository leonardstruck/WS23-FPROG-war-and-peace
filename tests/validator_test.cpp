#include "doctest.h"
#include "../src/validator.h"

TEST_CASE("Validate valid args") {
    int argc = 4;
    char arg1[] = "./war_and_peace";
    char arg2[] = "peace_terms.txt";
    char arg3[] = "war_terms.txt";
    char arg4[] = "war_and_peace.txt";
    char* argv[] = {arg1, arg2, arg3, arg4};

    auto result = validator::validateArgs(argc, argv);
    std::vector<std::string> expected = {"./war_and_peace", "peace_terms.txt", "war_terms.txt", "war_and_peace.txt"};
    CHECK_EQ(result, expected);
}
TEST_CASE("Validate invalid args") {
    int argc = 3;
    char arg1[] = "./war_and_peace";
    char arg2[] = "peace_terms.txt";
    char arg3[] = "war_terms.txt";
    char* argv[] = {arg1, arg2, arg3};

    auto result = validator::validateArgs(argc, argv);
    CHECK_EQ(result, std::nullopt);
}

