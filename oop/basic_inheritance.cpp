#include <iostream>

// Define a Base class
class Base {
public:
    // Constructor
    Base() {
        std::cout << "Base Constructor called" << std::endl;
    }
    
    // Destructor
    virtual ~Base() {
        std::cout << "Base Destructor called" << std::endl;
    }
    
    // A simple member function
    void baseFunction() {
        std::cout << "Function of Base" << std::endl;
    }
    
    // A virtual function for demonstration
    virtual void virtualFunction() {
        std::cout << "Base virtualFunction" << std::endl;
    }
};

// Define a Derived class that inherits from Base
class Derived : public Base {
public:
    // Constructor
    Derived() {
        std::cout << "Derived Constructor called" << std::endl;
    }
    
    // Destructor
    ~Derived() override {
        std::cout << "Derived Destructor called" << std::endl;
    }
    
    // Override the virtual function in the Base class
    void virtualFunction() override {
        std::cout << "Derived virtualFunction" << std::endl;
    }
};

int main() {
    // Create an instance of Base
    std::cout << "Creating Base object" << std::endl;
    Base b;
    b.baseFunction();
    b.virtualFunction();
    
    // Create an instance of Derived
    std::cout << "\nCreating Derived object" << std::endl;
    Derived d;
    d.baseFunction(); // Inherited from Base
    d.virtualFunction(); // Overridden in Derived

    // Upcasting: Pointing to Derived using Base pointer
    std::cout << "\nUpcasting in action" << std::endl;
    Base* basePtr = &d;
    basePtr->baseFunction(); // Calls Base's version
    basePtr->virtualFunction(); // Calls Derived's version due to virtual dispatch

    return 0;
    // Note: The destructors will be called automatically when objects go out of scope
}
