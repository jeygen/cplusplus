#include "Cat.h"

void Cat::makeSound() {
    std::cout << "The cat meows." << std::endl;
}

void Cat::makeSound(int volume) {
    std::cout << "The cat meows loudly at volume " << volume << "." << std::endl;
}
