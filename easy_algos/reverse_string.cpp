#include <algorithm>
#include <string>
#include <iostream>

// Using reverse function from <algorithm> header
std::string reverseStringUsingReverse(const std::string& str) {
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

// Using a loop to swap characters
std::string reverseStringUsingLoop(const std::string& str) {
    std::string reversed = str;
    int left = 0;
    int right = reversed.size() - 1;
    while (left < right) {
        std::swap(reversed[left], reversed[right]);
        left++;
        right--;
    }
    return reversed;
}

// Using recursion
void reverseStringRecursive(std::string& str, int left, int right) {
    if (left >= right) {
        return;
    }
    std::swap(str[left], str[right]);
    reverseStringRecursive(str, left + 1, right - 1);
}

std::string reverseStringUsingRecursion(const std::string& str) {
    std::string reversed = str;
    reverseStringRecursive(reversed, 0, reversed.size() - 1);
    return reversed;
}

int main() {
    std::string str = "Hello, World!";
    
    // Using reverse function
    std::string reversed1 = reverseStringUsingReverse(str);
    std::cout << "Reversed (using reverse function): " << reversed1 << std::endl;
    
    // Using loop
    std::string reversed2 = reverseStringUsingLoop(str);
    std::cout << "Reversed (using loop): " << reversed2 << std::endl;
    
    // Using recursion
    std::string reversed3 = reverseStringUsingRecursion(str);
    std::cout << "Reversed (using recursion): " << reversed3 << std::endl;

    return 0;
}

