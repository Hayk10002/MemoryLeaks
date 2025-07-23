#include <iostream>
#include <string>

// leaks if failEarly is true
std::string* getMessage(bool failEarly) {

    std::string* msg = new std::string("Hello, LeakSan!");

    if (failEarly) return nullptr;

    return msg; 
}

int main(int argc, char* argv[]) {

    bool failEarly = false;

    // Parse --fail-early=0 or --fail-early=1 from command line
    if (argc > 1) {
        std::string arg = argv[1];
        const std::string prefix = "--fail-early=";
        if (arg.find(prefix) == 0) {
            std::string value = arg.substr(prefix.size());
            failEarly = (value == "1");
        }
    }

    std::string* result = getMessage(failEarly);

    if (result) {
        std::cout << *result << std::endl;
        delete result;
    }

    return 0;
}
