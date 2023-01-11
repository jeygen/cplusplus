#ifndef PERSON_H // this checks for other same named headers, skips to endif if found
#define PERSON_H

#include <string>

class Person {
public:
    std::string name;
    int age;

    void setName(std::string n);
    void setAge(int a);
    std::string getName();
    int getAge();
};

#endif

