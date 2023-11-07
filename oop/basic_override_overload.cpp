#include <iostream>

// Using default constructors

class Animal {
public:
    // doesn't need to virtual, changes type of polymorphism
    virtual void makeSound() {
        std::cout << "The animal makes a sound." << std::endl;
    }
};

// 'extend' class like this. include access mod
class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "The cat meows." << std::endl;
    }

    void makeSound(int volume) {
        std::cout << "The cat meows loudly at volume " << volume << "." << std::endl;
    }
};

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
