#ifndef PRINT_H
#define PRINT_H

#include <iostream>

namespace print {
  auto printResult = [](const std::vector<std::pair<double,double>>& result, size_t chapterCount) {
    for (size_t i = 1; i< chapterCount; i++){
      std::cout << "Chapter " << i << ": ";
      if(result[i].first > result[i].second){
          std::cout << "peace-related" << std::endl;
      } else {
          std::cout << "war-related" << std::endl;
      }
    }
  };
}

#endif // PRINT_H