#include <iostream>

// nullptr safer to use than NULL macro

int main() {
    int* ptr = nullptr; // initialize a null pointer named ptr

    if (ptr == nullptr) { // check if ptr is null
        std::cout << "ptr is null" << std::endl;
    }

    // allocate memory for an integer on the heap using new
    ptr = new int(5);

    if (ptr != nullptr) { // check if ptr is not null
        std::cout << "ptr points to: " << *ptr << std::endl;
    }

    // free the memory on the heap using delete and set ptr to null
    delete ptr;
    ptr = nullptr;

    if (ptr == nullptr) { // check if ptr is null after deletion
        std::cout << "ptr is null" << std::endl;
    }

    return 0;
}
