#include <iostream>
#include "Animal.h"
#include "Cat.h"

int main() {
    Animal* animal = new Animal();
    animal->makeSound();

    Cat* cat = new Cat();
    cat->makeSound();
    cat->makeSound(10);

    Animal* catAsAnimal = new Cat();
    catAsAnimal->makeSound();
    
    /*
    Should have used smart pointers
    
    std::unique_ptr<Animal> animal = std::make_unique<Animal>();
    animal->makeSound();

    std::unique_ptr<Cat> cat = std::make_unique<Cat>();
    cat->makeSound();
    cat->makeSound(10);

    std::shared_ptr<Animal> catAsAnimal = std::make_shared<Cat>();
    catAsAnimal->makeSound();
    */

    return 0;
}
