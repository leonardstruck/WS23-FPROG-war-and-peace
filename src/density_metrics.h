#ifndef WAR_AND_PEACE_DENSITY_METRICS_H
#define WAR_AND_PEACE_DENSITY_METRICS_H

#include <range/v3/all.hpp>
#include "filter.h"
#include "counter.h"

/*
 * The density of a word, or set of words, is defined as the number of occurrences of the word(s)
 * divided by the average distance between occurrences.
 * For example, if the word "apple" occurs 3 times in a text, and the average distance between
 * occurrences is 2, then the density of "apple" is 1.5.
 * If the word "apple" occurs 3 times in a text, but all 3 occurrences are consecutive, then the
 * average distance is 1, and the density is 3.
 */

namespace density_metrics {
    auto occurrences = [](const auto& words, const auto& filter) -> int {
        const auto matches = filter::filter_words(words, filter);
        const auto occurrences = counter::count_words_parallel(matches);
        const auto sum_of_occurrences = counter::sum_of_counts(occurrences);

        return sum_of_occurrences;
    };

    auto distances = [](const auto& words, const auto& filter) -> std::vector<int> {
        const auto indices = filter::positions_of_matches(words, filter);

        // calculate the distance between each pair of indices
        // sliding(2) will create a view of the indices with a sliding window of size 2
        // transform will calculate the distance between each pair of indices

        auto distances = indices | ranges::views::sliding(2) | ranges::views::transform([](const auto& pair) {
            return pair[1] - pair[0];
        }) | ranges::to<std::vector<int>>;

        return distances;
    };

    auto average_distance = [](const auto& words, const auto& filter) -> double {
        const auto distances = density_metrics::distances(words, filter);
        const auto sum_of_distances = ranges::accumulate(distances, 0);

        // if there are no matches, then the average distance is 0
        if (sum_of_distances == 0) {
            return 0;
        }

        const auto number_of_distances = distances.size();
        const auto average_distance = static_cast<double>(sum_of_distances) / number_of_distances;

        return average_distance;
    };

    auto calculate_density = [](const auto& words, const auto& filter) -> double {
        const auto sum_of_occurrences = density_metrics::occurrences(words, filter);
        const auto average_distance = density_metrics::average_distance(words, filter);

        // if there are no matches, or if the average distance is 0, then the density is 0
        if (sum_of_occurrences == 0 || average_distance == 0) {
            return 0;
        }

        const auto density = static_cast<double>(sum_of_occurrences) / average_distance;
        return density;
    };
}

#endif //WAR_AND_PEACE_DENSITY_METRICS_H
