#include "doctest.h"
#include "../src/process.h"


TEST_CASE("process_chapter"){
  std::vector<std::string> fruits = {"apple", "banana", "cherry"};
  std::vector<std::string> vegetables = {"carrot", "potato", "tomato"};

  SUBCASE("more fruits than vegetables"){
    std::vector<std::string> words = {"apple", "carrot", "cherry", "banana", "apple"};
    
    auto result = process::process_chapter(words, fruits, vegetables);
    CHECK(result.first > result.second);
  }
  SUBCASE("more vegetables than fruits"){
    std::vector<std::string> words = {"potato", "carrot", "cherry", "tomato", "apple"};
    
    auto result = process::process_chapter(words, fruits, vegetables);
    CHECK(result.first < result.second);
  }

}
TEST_CASE("process"){
  std::vector<std::string> fruits = {"apple", "banana", "cherry"};
  std::vector<std::string> vegetables = {"carrot", "potato", "tomato"};

  SUBCASE("more fruits than vegetables"){
    std::vector<std::string> words1 = {"potato", "carrot", "cherry", "tomato", "apple"};
    std::vector<std::string> words2 = {"apple", "carrot", "cherry", "banana", "apple"};

    auto book = std::vector<std::vector<std::string>>{words1, words2};
    
    auto result = process::process(book, fruits, vegetables);
    CHECK(result.size() == book.size());
  }
}