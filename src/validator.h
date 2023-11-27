#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <iostream>
#include <vector>
#include <string>
#include <range/v3/all.hpp>
#include "readFile.h"

namespace validator {
  auto validateArgs = [](int argc, char* argv[]) -> std::optional<std::vector<std::string>> {
    // es müssen genau drei Dateien übergeben werden (book, war terms, peace terms)
    if (argc != 4) {
        return std::nullopt;
    }
    std::vector<std::string> args(argv, argv + argc);
    return args;
  };
}

#endif //VALIDATOR_H