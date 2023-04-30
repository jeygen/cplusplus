#include <iostream>

// Same as C, argc = # of args inc. name, argv is array of strings        

int main(int argc, char* argv[]) {
    std::cout << "Program name: " << argv[0] << std::endl;
    for (int i = 1; i < argc; i++) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }
    return 0;
}

