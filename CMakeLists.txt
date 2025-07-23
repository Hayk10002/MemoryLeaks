cmake_minimum_required(VERSION 3.10)

project(MemoryLeaks)

set(CMAKE_CXX_STANDARD 23)

add_executable(leak main_leak.cpp)
target_compile_options(leak PRIVATE -fsanitize=leak)
target_link_options(leak PRIVATE -fsanitize=leak)

add_executable(no_leak main_leak.cpp)
target_compile_options(no_leak PRIVATE -fsanitize=leak)
target_link_options(no_leak PRIVATE -fsanitize=leak)

# Add the leak executable as a test
enable_testing()

add_test(NAME LeakTest COMMAND leak)
set_tests_properties(LeakTest PROPERTIES WILL_FAIL TRUE)

add_test(NAME NoLeakTest COMMAND no_leak)