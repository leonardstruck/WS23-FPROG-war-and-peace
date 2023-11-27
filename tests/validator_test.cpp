#include "doctest.h"
#include "../src/validator.h"

TEST_CASE("Validate valide args") {
    int argc = 4;
    char* argv[] = {"./war_and_peace", "peace_terms.txt", "war_terms.txt", "war_and_peace.txt"};

    auto result = validator::validateArgs(argc, argv);
    std::vector<std::string> expected = {"./war_and_peace", "peace_terms.txt", "war_terms.txt", "war_and_peace.txt"};
    CHECK_EQ(result, expected);
}
TEST_CASE("Validate invalide args") {
    int argc = 3;
    char* argv[] = {"./war_and_peace", "peace_terms.txt", "war_terms.txt"};

    auto result = validator::validateArgs(argc, argv);
    CHECK_EQ(result, std::nullopt);
}

