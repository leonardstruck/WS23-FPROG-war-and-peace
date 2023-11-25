#ifndef CHAPTERIZER_H
#define CHAPTERIZER_H

#include <iostream>
#include <range/v3/all.hpp>

namespace chapterizer{
  // bekommt einen vector mit allen tokens und gibt einen vector<vector<string>>, der in die Kapitel aufgeteilt ist zurück
  auto split = ranges::views::split("chapter");

  auto filter_empty_ranges = ranges::views::filter([](auto&& range) {
    return !ranges::empty(range);
  });

  auto to_vector_vector = ranges::to<std::vector<std::vector<std::string>>>;

  auto chapterize = [](auto&& tokens) -> std::vector<std::vector<std::string>> {
    return tokens | split | filter_empty_ranges | to_vector_vector;
  };
}

#endif // CHAPTERIZER_H