#include "person.h"
#include <iostream>

int main() {
    Person p;
    p.setName("John");
    p.setAge(30);
    std::cout << p.getName() << " is " << p.getAge() << " years old." << std::endl;
    return 0;
}

