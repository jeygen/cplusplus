#include <iostream>

class Base {
public:
    // Non-virtual function, compile/static poly
    void NonVirtualFunction() {
        std::cout << "Base NonVirtualFunction called" << std::endl;
    }

    // Virtual function, runtime/dynamic poly
    virtual void VirtualFunction() {
        std::cout << "Base VirtualFunction called" << std::endl;
    }
};

class Derived : public Base {
public:
    // Override the non-virtual function
    void NonVirtualFunction() {
        std::cout << "Derived NonVirtualFunction called" << std::endl;
    }

    // Override the virtual function
    void VirtualFunction() override {
        std::cout << "Derived VirtualFunction called" << std::endl;
    }
};

int main() {
    Base* bPtr; 
    Derived dObj;

    // Pointing base class pointer to derived class object
    bPtr = &dObj; // Upcasting: Derived to Base

    // Calls NonVirtualFunction of Base class (not overridden)
    bPtr->NonVirtualFunction();

    // Calls VirtualFunction of Derived class (overridden)
    bPtr->VirtualFunction(); // Calls Derived's version, thanks to virtual mechanism

    /*
    Base* bPtr = new Derived(); // Upcasting
    Derived* dPtr = dynamic_cast<Derived*>(bPtr); // Downcasting
    if (dPtr) {
    dPtr->DerivedSpecificFunction(); // Calls function specific to Derived class
    }

    The crucial distinction, and the true utility of virtual functions, lies in 
    their ability to allow objects of derived classes to be treated polymorphically
    . When a base class defines a virtual function, and a derived class overrides 
    that function, the version of the function that gets invoked is determined by
    the actual type of the object that the base pointer or reference is pointing 
    to at runtime, not by the type of the pointer or reference itself. This is 
    what is meant by dynamic binding or late binding.
    */

    return 0;
}
