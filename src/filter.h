#ifndef WAR_AND_PEACE_FILTER_H
#define WAR_AND_PEACE_FILTER_H

#include <unordered_set>
#include <range/v3/all.hpp>

namespace filter {
    // Function to create a set from a list of words for efficient lookup (O(1))
    auto create_set = [](const auto& words) {
        return std::unordered_set<std::string>(words.begin(), words.end());
    };

    auto create_set_pluralized = [](const auto& words) {
        // create a set of words and add an "s" to each word
        // this is just a basic implementation, but it should be sufficient for this exercise
        // a more robust implementation would need to handle irregular plural forms (e.g. "child" vs "children")
        auto pluralized_words = words | ranges::views::transform([](auto&& word) {
            return word + "s";
        });
        return create_set(pluralized_words);
    };

    auto filter_predicate = [](const auto& filter_set, const auto& filter_set_pluralized, const auto& word) {
        // if the word is in either the singular or pluralized set, then it is a match
        return filter_set.contains(word) || filter_set_pluralized.contains(word);
    };

    auto filter_word = [](const auto& word, const auto& filter) {
        const auto& filter_set = create_set(filter);
        const auto& filter_set_pluralized = create_set_pluralized(filter);

        return filter_predicate(filter_set, filter_set_pluralized, word);
    };

    auto filter_words = [](const auto& words, const auto& filter) {
        const auto& filter_set = create_set(filter);
        const auto& filter_set_pluralized = create_set_pluralized(filter);

        return words | ranges::views::filter([&filter, &filter_set, &filter_set_pluralized](const auto& word) {
            return filter_predicate(filter_set, filter_set_pluralized, word);
        }) | ranges::to<std::vector<std::string>>;
    };
}

#endif //WAR_AND_PEACE_FILTER_H
