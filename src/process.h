#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include "density_metrics.h"

namespace process {
  // calculate for each chapter the density of war and peace terms

  auto process = [](auto&& chapters, auto&& warTerms, auto&& peaceTerms) -> std::vector<std::vector<double>> {

    std::vector<double> peaceDensities;
    std::vector<double> warDensities;

    //todo make for loop functional
    // for(auto chapter : chapters) {
    //   auto peaceDensity = density_metrics::calculate_density(chapter, peaceTerms);
    //   auto warDensity = density_metrics::calculate_density(chapter, warTerms);

    //   peaceDensities.push_back(peaceDensity);
    //   warDensities.push_back(warDensity);
    // }

    peaceDensities = chapters | ranges::views::transform([&](auto&& chapter) {
      return density_metrics::calculate_density(chapter, peaceTerms);
    }) | ranges::to<std::vector<double>>;
    warDensities = chapters | ranges::views::transform([&](auto&& chapter) {
      return density_metrics::calculate_density(chapter, warTerms);
    }) | ranges::to<std::vector<double>>;
    
    auto result = {peaceDensities, warDensities};
    return result;    
  };
}

#endif // PROCESS_H