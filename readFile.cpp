#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>


auto readFile = [](const std::string path) -> std::optional<std::string>
{
  std::ifstream file;
  file.open(path);

  if (!file) {
    return std::nullopt;
  }

  std::stringstream buffer;
  buffer << file.rdbuf();
  file.close();
  return buffer.str();
};