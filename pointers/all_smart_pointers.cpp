#include <iostream>
#include <memory>

class Person {
public:
    Person(std::string name) : name_(name) {
        std::cout << "Constructing person: " << name_ << std::endl;
    }

    ~Person() {
        std::cout << "Destructing person: " << name_ << std::endl;
    }

    void greet() {
        std::cout << "Hello, my name is " << name_ << std::endl;
    }

private:
    std::string name_;
};

int main() {
    // unique pointer example
    {
        std::unique_ptr<Person> ptr(new Person("Alice")); // create a unique pointer to a dynamically allocated Person object
        ptr->greet(); // call a method on the object using the dereference operator ->

        // once the block is exited, the unique pointer goes out of scope and automatically deallocates the object
    }

    // shared pointer example // counts references, good for multi threading apps. Owns ref.
    {
        std::shared_ptr<Person> ptr1(new Person("Bob")); // create a shared pointer to a dynamically allocated Person object
        std::shared_ptr<Person> ptr2 = ptr1; // create another shared pointer that points to the same object

        ptr1->greet(); // call a method on the object using the dereference operator ->
        ptr2->greet(); // call a method on the object using the dereference operator ->

        // the object is automatically deallocated when the last shared pointer goes out of scope
    }

    // weak pointer example // doesnt ouwn ref, ie cant deref * or ->, needs to be locked to convert to shared
    {
        std::shared_ptr<Person> ptr1(new Person("Charlie")); // create a shared pointer to a dynamically allocated Person object
        std::weak_ptr<Person> ptr2 = ptr1; // create a weak pointer that points to the same object

        // use the lock() method to create a shared pointer from the weak pointer
        if (std::shared_ptr<Person> ptr3 = ptr2.lock()) {
            ptr3->greet(); // call a method on the object using the dereference operator ->
        }

        // the object is automatically deallocated when the last shared pointer goes out of scope
    }

    return 0;
}
