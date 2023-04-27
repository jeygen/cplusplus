#include <iostream>
#include <memory> // include the <memory> header to use unique pointers

int main() {
    // create a unique pointer that points to a dynamically allocated integer
    std::unique_ptr<int> ptr(new int(5));

    // print the value of the integer using the dereference operator *
    std::cout << "Value of ptr: " << *ptr << std::endl;

    // change the value of the integer using the dereference operator *
    *ptr = 10;

    // print the new value of the integer
    std::cout << "New value of ptr: " << *ptr << std::endl;

    // create another unique pointer that points to a dynamically allocated integer
    std::unique_ptr<int> ptr2(new int(7));

    // transfer ownership of the integer from ptr to ptr2 using std::move()
    ptr2 = std::move(ptr);

    // print the value of the integer using the dereference operator *
    std::cout << "Value of ptr2: " << *ptr2 << std::endl;

    // check if ptr is null (it should be null after ownership transfer)
    if (ptr == nullptr) {
        std::cout << "ptr is null" << std::endl;
    }

    // use the reset() method to release ownership and delete the object pointed to by ptr2
    ptr2.reset();

    // check if ptr2 is null (it should be null after reset)
    if (ptr2 == nullptr) {
        std::cout << "ptr2 is null" << std::endl;
    }

    return 0;
}
