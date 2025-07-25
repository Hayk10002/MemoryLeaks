# MemoryLeaks

## Table of Contents
- [Introduction](#introduction)
- [Build and Run](#build-and-run)
- [Possible Output](#possible-output)
- [How does this work](#how-does-this-work)

## Introduction
This project demonstrates the work of a leak sanitizer on a very simple code.

## Build and Run
To clone and run this project, ensure you have [Git](https://git-scm.com) and [CMake](https://cmake.org/) installed. Use the following commands:

```bash
# Clone this repository
$ git clone https://github.com/Hayk10002/MemoryLeaks

# Navigate to the repository
$ cd MemoryLeaks

# Generate build files
$ cmake -DCMAKE_BUILD_TYPE=Release -S . -B build

# Build the project
$ cmake --build build --config Release

# Run the executable with the desired vector size
$ your/path/to/exe/main.exe --fail-early={0 or 1}
# Example: .../main.exe -fail-early=1 # This will leak memory, and 0 will not leak
```

## Possible Output
If you see the Action section in the github, and open the latest run's Test section, you will see two tests, which pass, but first one pass because it leaks memory, so you will see the leak sanitizer output.

## How does this work
The benchmark results show that sequential access times remain consistently low across all tested vector sizes, while random access times increase as the vector size grows. Notably, random access time jumps significantly at around 400M elements (from ~177ms to ~205ms) and again at 600M elements (from ~214ms to ~268ms). These jumps indicate the point where the system starts swapping memory to disk due to insufficient physical RAM, causing slower access times. This demonstrates how random access performance is affected by memory swapping, while sequential access remains largely unaffected.