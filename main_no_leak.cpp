#include <iostream>
#include <string>

// leaks if failEarly is true
std::string* getMessage(bool failEarly) {

    std::string* msg = new std::string("Hello, Valgrind!");

    if (failEarly) return nullptr;

    return msg; 
}

int main() {
    std::string* result = getMessage(false);

    if (result) {
        std::cout << *result << std::endl;
        delete result;
    }

    return 0;
}
