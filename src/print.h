#ifndef PRINT_H
#define PRINT_H

#include <iostream>

namespace print {
  auto printResult = [](auto&& result, size_t chapterCount) {
    for (size_t i = 1; i< chapterCount; i++){
      std::cout << "Chapter " << i << ": ";
      if(result[0][i] > result[1][i]){
          std::cout << "peace-related" << std::endl;
      } else {
          std::cout << "war-related" << std::endl;
      }
    }
  };
}

#endif // PRINT_H