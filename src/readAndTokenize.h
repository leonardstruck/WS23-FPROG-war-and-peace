#ifndef READANDTOKENIZE_H
#define READANDTOKENIZE_H

#include <iostream>
#include <vector>
#include <string>
#include <range/v3/all.hpp>
#include "tokenizer.h"
#include "readFile.h"

namespace readAndTokenize {
  auto validateArgs = [](int argc, char* argv[]) -> std::optional<std::vector<std::string>> {
    // es müssen genau drei Dateien übergeben werden (book, war terms, peace terms)
    if (argc != 4) {
        return std::nullopt;
    }
    std::vector<std::string> args(argv, argv + argc);
    return args;
  };

  auto readAndTokenize = [](const std::string path) -> std::optional<std::vector<std::string>> {
      auto file = readFile::readFile(path);
      if (!file) {
          return std::nullopt;
      }
      return tokenizer::tokenize(*file);
  };

  auto validateAndTokenize = [](int argc, char* argv[]) -> std::optional<std::vector<std::vector<std::string>>>{
    auto args = validateArgs(argc, argv);
    if (!args.has_value()) {
      return std::nullopt;
    }
    std::vector<std::vector<std::string>> tokens = args.value() | ranges::views::drop(1)
      | ranges::views::transform([](const std::string& arg) {
          auto token = readAndTokenize(arg);
          return token.has_value() ? token.value() : std::vector<std::string>{};
      })
      | ranges::views::take_while([](const std::vector<std::string>& token) {
          return !token.empty();
      })
      | ranges::to<std::vector<std::vector<std::string>>>;

    if (tokens.size() < (args.value().size() - 1)) {
      return std::nullopt;
    }

    return tokens;
  };
}

#endif // READANDTOKENIZE_H