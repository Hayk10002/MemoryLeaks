cmake_minimum_required(VERSION 3.10)

project(MemoryLeaks)

set(CMAKE_CXX_STANDARD 23)

add_executable(main main.cpp)
target_compile_options(main PRIVATE -fsanitize=leak)
target_link_options(main PRIVATE -fsanitize=leak)

# Add the main executable as a test
enable_testing()

add_test(NAME MemoryLeaksTest COMMAND main)
set_tests_properties(MemoryLeaksTest PROPERTIES WILL_FAIL TRUE)