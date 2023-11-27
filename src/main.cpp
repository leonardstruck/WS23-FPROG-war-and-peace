#include <iostream>
#include "tokenizer.h"
#include "readFile.h"
#include "validator.h"
#include "chapterizer.h"
#include "process.h"
#include "print.h"


int main(int argc, char* argv[]) {
    auto args = validator::validateArgs(argc, argv);
    if (!args.has_value()) {
        std::cout << "Invalid arguments" << std::endl;
        std::cout << "Please provide the paths to the book, war terms and peace terms files" << std::endl;
        std::cout << "Usage: " << "war_and_peace" << " <peace terms> <war terms> <text>" << std::endl;
        return 1;
    }

    auto peaceTermsFile = readFile::readFile(args.value()[1]);
    auto warTermsFile = readFile::readFile(args.value()[2]);
    auto textFile = readFile::readFile(args.value()[3]);

    if(!peaceTermsFile.has_value() || !warTermsFile.has_value() || !textFile.has_value()) {
        std::cout << "Failed to read file" << std::endl;
        return 1;
    }

    auto peaceTerms = tokenizer::tokenize(peaceTermsFile.value()); 
    auto warTerms = tokenizer::tokenize(warTermsFile.value()); 
    auto text = tokenizer::tokenize(textFile.value()); 

    // separate text into chapters by looking for the word "chapter"
    auto chapters = chapterizer::chapterize(text);

    auto densities = process::process(chapters, warTerms, peaceTerms);


    // print result
    print::printResult(densities, chapters.size());


    return 0;
}
