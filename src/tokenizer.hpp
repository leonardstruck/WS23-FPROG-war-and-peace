#include <iostream>
#include <range/v3/all.hpp>
#include <cctype> // for std::ispunct

namespace tokenizer {
    auto to_string = ranges::to<std::string>;
    auto to_vector = ranges::to<std::vector<std::string>>;

    auto to_lower = ranges::views::transform([](char c) {
        return std::tolower(c);
    });

    auto replace_punctuation_with_spaces = ranges::views::transform([](char c) {
        return std::ispunct(c) ? ' ' : c;
    });

    auto replace_non_printable_characters_with_spaces = ranges::views::transform([](char c) {
        return std::isprint(c) ? c : ' ';
    });

    // combines the above views into a single view that can be used to sanitize input
    auto sanitize = to_lower | replace_non_printable_characters_with_spaces | replace_punctuation_with_spaces;

    // since we are splitting on spaces and replaced any unwanted characters with spaces,
    // there may be empty ranges in the result. this view filters out those empty ranges.
    auto filter_empty_ranges = ranges::views::filter([](auto&& range) {
        return !ranges::empty(range);
    });

    auto split = ranges::views::split(' ');

    // This method combines all the above views and returns a vector of strings
    // that represent the tokens in the input string.
    auto tokenize = [](auto&& input) -> std::vector<std::string> {
        return input | sanitize | split | filter_empty_ranges | to_vector;
    };
}

