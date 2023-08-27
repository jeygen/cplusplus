/*
    Generality: 
		**Iterators allow for writing code that can work with any container type**

    Abstraction: 
		They hide the specifics of the underlying container, allowing the same code to be used with different container types.

    Flexibility: 
		Different types of iterators (input, output, forward, bidirectional, random access) provide varying levels of functionality based on the needs of the algorithm.

    Efficiency: 
		Some operations can be performed more efficiently with iterators, such as inserting or deleting elements in the middle of a container.

**value you get when you dereference an iterator is a reference to the element in the container that the iterator is pointing to, and the type of this reference matches the type of the elements in the containe

*/

#include <iostream>
#include <vector>
#include <list>
#include <set>

int main() {
    // Let's create a vector
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Let's print the elements of the vector using iterators
    // can also just use 'auto' instead of writing the full datatype out
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    // Now, let's modify the vector elements using iterators
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        *it += 5;  // Add 5 to each element
    }

    // Print the modified vector
    for (const auto& elem : vec) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';

    // Let's create a set
    std::set<int> s = {5, 1, 3, 2, 4};

    // Print the set using iterators
    for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    // Let's create a list
    std::list<int> lst = {1, 2, 3, 4, 5};

    // Print the list using iterators
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    return 0;
}

