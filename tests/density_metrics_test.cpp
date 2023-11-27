#include "doctest.h"
#include "../src/density_metrics.h"

TEST_CASE("occurrences") {
    std::vector<std::string> words = {"apple", "banana", "apple", "cherry", "apple"};
    std::vector<std::string> filter = {"apple"};

    auto result = density_metrics::occurrences(words, filter);
    CHECK(result == 3); // "apple" occurs 3 times
}

TEST_CASE("distances") {
    SUBCASE("basic case") {
        std::vector<std::string> words = {"apple", "banana", "apple", "cherry", "apple"};
        std::vector<std::string> filter = {"apple"};
        auto result = density_metrics::distances(words, filter);
        CHECK(result.size() == 2);
        CHECK(result[0] == 2);
        CHECK(result[1] == 2);
    }

    SUBCASE("no occurrences") {
        std::vector<std::string> words = {"banana", "cherry", "grape"};
        std::vector<std::string> filter = {"apple"};
        auto result = density_metrics::distances(words, filter);
        CHECK(result.empty());
    }

    SUBCASE("single occurrence") {
        std::vector<std::string> words = {"apple", "banana", "cherry"};
        std::vector<std::string> filter = {"apple"};
        auto result = density_metrics::distances(words, filter);
        CHECK(result.empty());
    }

    SUBCASE("consecutive occurrences") {
        std::vector<std::string> words = {"apple", "apple", "banana", "apple"};
        std::vector<std::string> filter = {"apple"};
        auto result = density_metrics::distances(words, filter);
        CHECK(result.size() == 2);
        CHECK(result[0] == 1); // Distance between first and second "apple"
        CHECK(result[1] == 2); // Distance between second and third "apple"
    }

    SUBCASE("all matches") {
        std::vector<std::string> words = {"apple", "apple", "apple"};
        std::vector<std::string> filter = {"apple"};
        auto result = density_metrics::distances(words, filter);
        CHECK(result.size() == 2);
        CHECK(result[0] == 1);
        CHECK(result[1] == 1);
    }
}

TEST_CASE("average_distance") {
    SUBCASE("basic case") {
        std::vector<std::string> words = {"apple", "banana", "apple", "cherry", "apple"};
        std::vector<std::string> filter = {"apple"};
        auto result = density_metrics::average_distance(words, filter);
        CHECK(result == doctest::Approx(2.0)); // Average distance is 2
    }

    SUBCASE("no occurrences") {
        std::vector<std::string> words = {"banana", "cherry", "grape"};
        std::vector<std::string> filter = {"apple"};
        auto result = density_metrics::average_distance(words, filter);
        CHECK(result == 0.0); // No occurrences, so average distance is 0
    }

    SUBCASE("single occurrence") {
        std::vector<std::string> words = {"apple", "banana", "cherry"};
        std::vector<std::string> filter = {"apple"};
        auto result = density_metrics::average_distance(words, filter);
        CHECK(result == 0.0); // Single occurrence, so average distance is 0
    }

    SUBCASE("consecutive occurrences") {
        std::vector<std::string> words = {"apple", "apple", "banana", "apple"};
        std::vector<std::string> filter = {"apple"};
        auto result = density_metrics::average_distance(words, filter);
        CHECK(result == doctest::Approx(1.5)); // Average distance is 1.5 (1 + 2 / 2)
    }
}

TEST_CASE("calculate_density") {
    SUBCASE("calculate_density - basic case") {
        std::vector<std::string> words = {"apple", "banana", "apple", "cherry", "apple"};
        std::vector<std::string> filter = {"apple"};
        auto result = density_metrics::calculate_density(words, filter);
        CHECK(result == doctest::Approx(1.5)); // Density: occurrences (3) / average distance (2)
    }

    SUBCASE("calculate_density - no occurrences") {
        std::vector<std::string> words = {"banana", "cherry", "grape"};
        std::vector<std::string> filter = {"apple"};
        auto result = density_metrics::calculate_density(words, filter);
        CHECK(result == 0.0); // No occurrences, so density is 0
    }

    SUBCASE("calculate_density - single occurrence") {
        std::vector<std::string> words = {"apple", "banana", "cherry"};
        std::vector<std::string> filter = {"apple"};
        auto result = density_metrics::calculate_density(words, filter);
        CHECK(result == 0.0); // Single occurrence, undefined distance, so density is 0
    }

    SUBCASE("calculate_density - consecutive occurrences") {
        std::vector<std::string> words = {"apple", "apple", "banana", "apple"};
        std::vector<std::string> filter = {"apple"};
        auto result = density_metrics::calculate_density(words, filter);
        CHECK(result == doctest::Approx(2.0)); // Density: occurrences (3) / average distance (1.5)
    }

    SUBCASE("calculate_density - uniform distance") {
        std::vector<std::string> words = {"apple", "banana", "apple", "banana", "apple"};
        std::vector<std::string> filter = {"apple"};
        auto result = density_metrics::calculate_density(words, filter);
        CHECK(result == doctest::Approx(1.5)); // Density: occurrences (3) / average distance (2)
    }

    SUBCASE("calculate_density - large distances") {
        std::vector<std::string> words = {"apple", "banana", "cherry", "grape", "banana", "apple"};
        std::vector<std::string> filter = {"apple"};
        auto result = density_metrics::calculate_density(words, filter);
        CHECK(result == doctest::Approx(0.4)); // Density: occurrences (2) / average distance (5)
    }

    SUBCASE("calculate_density - different filters") {
        std::vector<std::string> words = {"apple", "banana", "cherry", "grape", "banana", "strawberry"};
        std::vector<std::string> filter = {"apple", "strawberry"};
        auto result = density_metrics::calculate_density(words, filter);
        CHECK(result == doctest::Approx(0.4)); // Density: occurrences (2) / average distance (5)
    }
}