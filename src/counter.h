#ifndef WAR_AND_PEACE_COUNTER_H
#define WAR_AND_PEACE_COUNTER_H

#include <map>
#include <range/v3/all.hpp>
#include <future>

namespace counter {
    typedef std::map<std::string, int> CountMap;

    auto count_words = [](const auto& tokens) -> CountMap {
        return ranges::accumulate(tokens, CountMap{}, [](auto& map, const auto& token) {
            map[token]++;
            return map;
        });
    };

    auto merge_counts = [](const CountMap& map1, const CountMap& map2) -> CountMap {
        return ranges::accumulate(map2, map1, [](auto& map, const auto& pair) {
            map[pair.first] += pair.second;
            return map;
        });
    };

    auto count_words_parallel = [](const auto& tokens, const int chunk_size = 1000) -> CountMap {
        auto chunks = tokens | ranges::views::chunk(chunk_size);

        auto futures = chunks | ranges::views::transform([](const auto& chunk) {
            return std::async(std::launch::async, count_words, chunk);
        }) | ranges::to_vector;

        // future.get() will block the current thread until the result is ready. Since the futures
        // are running in separate threads, this does not affect our desired parallelism.
        // This is merely a convenience to avoid having to call .get() on each future individually and
        // then merge the results.
        auto result = ranges::accumulate(futures, CountMap{}, [](auto& map, auto& future) {
            return merge_counts(map, future.get());
        });

        return result;
    };
}

#endif //WAR_AND_PEACE_COUNTER_H
