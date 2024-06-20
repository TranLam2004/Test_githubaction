cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SampleProject)

# Add the executable for the main program
add_executable(main src/main.cpp)

# Enable testing
enable_testing()

# Add the test executable
add_executable(test_main tests/test_main.cpp)

# Register the test
add_test(NAME TestMain COMMAND test_main)
