#ifndef READANDTOKENIZE_H
#define READANDTOKENIZE_H

#include <iostream>
#include "tokenizer.h"
#include "readFile.h"

namespace readAndTokenize {
  auto validateArgs = [](int argc, char* argv[]) -> std::optional<std::vector<std::string>> {
    // es müssen genau drei Dateien übergeben werden (book, war terms, peace terms)
    if (argc != 4) {
        return std::nullopt;
    }
    return std::vector<std::string> args(std::begin(argv), std::end(argv));
  };

  auto readAndTokenize = [](const std::string path) -> std::optional<std::vector<std::string>> {
      auto file = readFile(path);
      if (!file) {
          return std::nullopt;
      }
      return tokenizer::tokenize(*file);
  };

  auto validateAndTokenize = [](int argc, char* argv[]) {
    auto args = validateArgs(argc, argv);
    if (!args) {
      return std::nullopt;
    }
    std::transform(args.begin(), args.end(), args.begin(), [](const std::string& arg) -> std::string {
      auto tokens = readAndTokenize(arg);
      return tokens ? *tokens : std::nullopt;
    });
    return args;
  }
}

#endif // READANDTOKENIZE_H