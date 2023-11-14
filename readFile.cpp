#include <iostream>
#include <fstream>
#include <sstream>


auto readFile = [](const std::string path){
  // filepfad als String
  std::ifstream file;
  file.open(path);

  std::stringstream buffer;
  buffer << file.rdbuf();
  return buffer.str();

};