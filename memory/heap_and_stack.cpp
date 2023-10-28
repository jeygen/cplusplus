#include <iostream>
#include <vector>

class ExampleClass {
public:
    int stackVar; // A variable on the stack, within an object
    int* heapVar; // A pointer that will point to a variable on the heap
    std::vector<int> numbers; // Stack: Vector object itself is on the stack,
                             // Heap: but manages dynamic memory on the heap for its elements.

    ExampleClass(int s, int h, const std::vector<int>& nums) : stackVar(s), numbers(nums) {
        heapVar = new int(h); // Allocating memory on the heap
    }

    ~ExampleClass() {
        delete heapVar; // Deallocating heap memory
    }
};

int main() {
    int stackInt = 42; // Stack: Simple integer allocated on the stack

    int* heapInt = new int(99); // Heap: Integer allocated on the heap

    std::vector<int> nums = {1, 2, 3}; // Stack: Vector object itself is on the stack
                                       // Heap: But the integers within are managed dynamically on the heap

    ExampleClass example(stackInt, *heapInt, nums); // Stack: Object is on the stack
                                                    // Mixed: Contains members on both stack and heap

    // Accessing and printing values
    std::cout << "Stack integer: " << stackInt << std::endl;
    std::cout << "Heap integer: " << *heapInt << std::endl;
    std::cout << "Vector’s first element (managed on heap): " << nums[0] << std::endl;
    std::cout << "Example object’s stack variable: " << example.stackVar << std::endl;
    std::cout << "Example object’s heap variable: " << *(example.heapVar) << std::endl;
    std::cout << "Example object’s vector’s first element (managed on heap): " << example.numbers[0] << std::endl;

    delete heapInt; // Don't forget to delete heap-allocated simple variables

    return 0;
}
