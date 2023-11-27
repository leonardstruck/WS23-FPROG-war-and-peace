# Functional Analysis of Literary Themes

## Project Overview

This C++ project, developed for the Functional Programming course (FPROG), utilizes functional programming concepts to analyze literary texts. The program reads a large text file (e.g., "War and Peace" by Leo Tolstoy) and categorizes its chapters as either war-related or peace-related based on the density of specific terms. This is achieved using two additional text files: one containing war-related terms and another with peace-related terms.


## How to compile

We are using cmake to compile the project. To compile the project, run the following commands in the project's root directory:

``` 
mkdir build
cd build
cmake ..
make
```

## How to run

To run the program, run the following command in the build directory:

```
./build/war_and_peace <peace_terms_file> <war_terms_file> <war_and_peace_file>
```

## bash script

We also included a bash script that compiles and runs the program with the files provided in the `./text/` directory. 
At the end of the program's execution, the script will print the time it took to run the program.
To run the script, run the following command in the project's root directory:

```
chmod +x run.sh
./run.sh
```