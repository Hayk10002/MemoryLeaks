#include <iostream>
#include <cstring>

// leaks if failEarly is true
char* getMessage(bool failEarly) {

    char MSG[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus auctor ex et mollis bibendum. Nulla ornare dolor vitae augue elementum tempus. Cras ac efficitur libero. Aliquam erat volutpat. Praesent et malesuada tellus. Aliquam convallis magna ut pulvinar laoreet. Nunc aliquam, nibh vitae pellentesque mollis, ex enim iaculis neque, accumsan molestie urna velit eget urna. Maecenas ex libero, interdum et ligula nec, fringilla efficitur nulla. Ut vel dui commodo, hendrerit neque quis, consectetur nulla. Vivamus pharetra eu erat at ornare. Duis varius libero vitae est efficitur varius. Curabitur dui risus, porttitor sed est finibus, porta faucibus mi. Duis suscipit ultrices ligula vel rhoncus. Nullam congue justo augue. ";
    char* msg = new char[800];

    std::strcpy(msg, MSG); 

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

    char* result = getMessage(failEarly);

    if (result) {
        std::cout << result << std::endl;
        delete result;
    }

    return 0;
}
