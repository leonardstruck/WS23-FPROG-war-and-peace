all: main

.outputFolder:
	mkdir -p out

main: .outputFolder
	clang -std=c++17 -lstdc++ -lm main.cpp -Wall -Wextra -Werror -o out/main
	./out/main
