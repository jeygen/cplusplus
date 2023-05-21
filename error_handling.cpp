/*
In C++, the standard library provides several built-in exception types derived from the std::exception base class. These exception types are defined in the <stdexcept> header and are commonly used for handling various exceptional conditions in C++ programs. Some of the commonly used exception types include:

1. std::exception: The base class for all standard exceptions. It provides a what() member function that returns an explanatory string describing the exception.

2. std::logic_error: Represents errors that are caused by logical flaws in the program. Derived classes include:
   - std::invalid_argument: Thrown when an invalid argument is passed to a function.
   - std::domain_error: Thrown when a mathematical domain error occurs, such as passing an out-of-range argument to a mathematical function.
   - std::length_error: Thrown when an attempt is made to create a container that exceeds its maximum size.

3. std::runtime_error: Represents errors that occur during runtime. Derived classes include:
   - std::overflow_error: Thrown when an arithmetic overflow occurs.
   - std::underflow_error: Thrown when an arithmetic underflow occurs.
   - std::range_error: Thrown when a value is out of its valid range.

4. std::bad_alloc: Thrown when dynamic memory allocation (new) fails due to insufficient memory.

These are just a few examples of the standard exception types provided by the C++ standard library. You can also define and throw your own custom exception types by deriving them from std::exception or any of the existing exception classes.

It's important to note that exception handling in C++ is not limited to these standard exceptions, and you can create and use your own exception types based on your specific program requirements.
*/

class MyClass {
public:
    void myMethod() {
        // Some code that may throw an exception
        if (/* some condition */) {
            throw MyException("Exception occurred");
        }
        // ...
    }
};

int main() {
    try {
        MyClass obj;
        obj.myMethod();
    }
    catch (const MyException& ex) {
        // Exception handling code
        // Handle or log the exception
    }
    // ...
}

