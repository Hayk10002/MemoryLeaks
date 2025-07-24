cmake_minimum_required(VERSION 3.10)

project(MemoryLeaks)

set(CMAKE_CXX_STANDARD 23)

add_executable(main main.cpp)
target_compile_options(main PRIVATE -fsanitize=address)
target_link_options(main PRIVATE -fsanitize=address)

# Add the leak executable as a test
enable_testing()

add_test(NAME LeakTest COMMAND main --fail-early=1)
set_tests_properties(LeakTest PROPERTIES WILL_FAIL TRUE)

add_test(NAME NoLeakTest COMMAND main --fail-early=0)