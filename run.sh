# create build directory if it doesn't exist
mkdir "build"
# change to build directory
cd "build"
# run cmake
cmake ..
# run make
make

# run tests
printf "\n\n"
echo "Running tests..."
echo "================"
printf "\n\n"
./tests/test

# run main program
printf "\n\n"
echo "Running main program..."
echo "======================"
printf "\n\n"

time ./war_and_peace ../text/peace_terms.txt ../text/war_terms.txt ../text/war_and_peace.txt