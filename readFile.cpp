#include <iostream>
#include <fstream>


auto readFile = [](const std::string path){
  // filepfad als String
  std::ifstream file;
  file.open(path);

  // file lesen
  std::string content = "";
  while ( file ) {
    std::string line = "";
    std::getline (file, line);
    content += line + '\n';
  }

  // return inhalt als string
  return content;
};