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

    return 0;
}
