#include <iostream>
#include "tokenizer.h"
#include "readFile.h"
#include "readAndTokenize.h"

int main(int argc, char* argv[]) {
    auto args = readAndTokenize::validateArgs(argc, argv);
    if (!args.has_value()) {
        // ToDo: Error handling
        return 1;
    }

    auto peaceTermsFile = readFile::readFile(args.value()[1]);
    auto warTermsFile = readFile::readFile(args.value()[2]);
    auto textFile = readFile::readFile(args.value()[3]);

    if(!peaceTermsFile.has_value() || !warTermsFile.has_value() || !textFile.has_value()) {
        return 1;
    }

    auto peaceTerms = tokenizer::tokenize(peaceTermsFile.value()); 
    auto warTerms = tokenizer::tokenize(warTermsFile.value()); 
    auto text = tokenizer::tokenize(textFile.value()); 

    return 0;
}
