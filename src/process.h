#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include "density_metrics.h"

namespace process {
  // calculate for each chapter the density of war and peace terms

  auto process_chapter = [](const auto& chapter, const auto& peaceTerms, const auto& warTerms) -> std::pair<double, double> {
    auto peaceDensity = density_metrics::calculate_density(chapter, peaceTerms);
    auto warDensity = density_metrics::calculate_density(chapter, warTerms);
    return {peaceDensity, warDensity};
  };

  auto process = [](auto&& chapters, auto&& warTerms, auto&& peaceTerms) -> std::vector<std::pair<double,double>> {

    auto futures = chapters | ranges::views::transform([&](const auto& chapter) {
      return std::async(std::launch::async, process_chapter, chapter, peaceTerms, warTerms);
    }) | ranges::to_vector;

    auto results = futures | ranges::views::transform([](auto& future) { return future.get(); }) | ranges::to_vector;

    return results;
  };
}

#endif // PROCESS_H