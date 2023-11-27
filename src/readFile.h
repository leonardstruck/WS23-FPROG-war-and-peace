#ifndef READFILE_H
#define READFILE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>

namespace readFile{
  auto readFile = [](const std::string path) -> std::optional<std::string>
  {
    try{
      std::ifstream file;
      file.open(path);

      if (!file) {
        return std::nullopt;
      }

      std::stringstream buffer;
      buffer << file.rdbuf();
      file.close();
      return buffer.str();

    } catch(...){
      return std::nullopt;
    }
  };
}

#endif // READFILE_H