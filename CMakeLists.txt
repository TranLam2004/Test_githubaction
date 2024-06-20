cmake_minimum_required(VERSION 3.10)

# Project name and version
project(SampleProject VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable for the main program
add_executable(main src/main.cpp)

# Enable testing
enable_testing()

# Download and configure GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Add executable for the test
add_executable(test_main tests/test_main.cpp)
target_link_libraries(test_main gtest gtest_main)

# Add test
add_test(NAME FileComparisonTest COMMAND test_main)

# Custom command to run the main program with testcase
add_custom_target(run_main
    COMMAND main
    DEPENDS main
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
