#include <iostream>

// cast friendly/need to cast to deref

int main() {
    int num = 5;
    float pi = 3.14159;
    char letter = 'a';

    void* ptr; // declare a void pointer

    ptr = &num; // assign the address of an integer to the void pointer
    std::cout << "Value of num: " << *(int*)ptr << std::endl; // cast the void pointer to an integer pointer and dereference it

    ptr = &pi; // assign the address of a float to the void pointer
    std::cout << "Value of pi: " << *(float*)ptr << std::endl; // cast the void pointer to a float pointer and dereference it

    ptr = &letter; // assign the address of a char to the void pointer
    std::cout << "Value of letter: " << *(char*)ptr << std::endl; // cast the void pointer to a char pointer and dereference it

    return 0;
}
