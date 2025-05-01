cmake_minimum_required(VERSION 3.4)

# Project name
project(gtest_enhancement)

# FetchContent to download GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        main
)
FetchContent_MakeAvailable(googletest)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# GoogleTest requires at least C++11
set(gtest_disable_pthreads on)

# Include directories
include_directories(
    ${googletest_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Define a macro for unit testing
add_definitions(-D__UNITTEST__)

# Add compile options
add_compile_options(-std=c++17 -fpermissive -g -fprofile-arcs -ftest-coverage)

# List of test files
set(TEST_SOURCES
    main.cpp
    sample_exception_test.cpp
)

# Add the executable for tests
add_executable(gtest_enhancement ${TEST_SOURCES})

# Link GoogleTest to the test executable
target_link_libraries(gtest_enhancement gtest gtest_main gcov gmock)

# Enable testing
enable_testing()

# Add test cases
add_test(NAME gtest_enhancement COMMAND gtest_enhancement)

# Custom taret: generate coverage
add_custom_target(coverage
    COMMAND ${CMAKE_COMMAND} -E env TEST_EXECUTABLE=$<TARGET_FILE:gtest_enhancement> bash ${CMAKE_SOURCE_DIR}/generate_coverage.sh
    DEPENDS gtest_enhancement
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running tests and generating coverage report"
)
