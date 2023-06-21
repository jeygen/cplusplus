// swap at least 3 ways

// fibo 

// factorial

// binary sort

// reverse string

// fizzbuzz

// bubble sorto

// count chars in string

#include <iostream>
#include <algorithm>
#include <string>
#include <map>

// Swap Functions
void swap1(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

void swap3(int &a, int &b) {
    std::swap(a, b);
}

// Swap function using pointers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


// Fibonacci
int fibonacci(int n) {
    if (n <= 1) return n;
    else return fibonacci(n-1) + fibonacci(n-2);
}

// Factorial
int factorial(int n) {
    if (n == 0) return 1;
    else return n * factorial(n - 1);
}

// Binary Search
int binary_search(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x) return m;
        if (arr[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

// Reverse String
std::string reverse_str(std::string str) {
    std::reverse(str.begin(), str.end());
    return str;
}

// Reverse string without using the built-in 'reverse' function
std::string reverseString(const std::string& str) {
    std::string reversedStr = "";
    for (int i = str.length() - 1; i >= 0; i--) {
        reversedStr += str[i];
    }
    return reversedStr;
}

// FizzBuzz
void fizzbuzz(int n) {
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) std::cout << "FizzBuzz\n";
        else if (i % 3 == 0) std::cout << "Fizz\n";
        else if (i % 5 == 0) std::cout << "Buzz\n";
        else std::cout << i << "\n";
    }
}

// Bubble Sort
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {     
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

// Count Characters in a String
std::map<char, int> count_chars(std::string str) {
    std::map<char, int> count;
    for (char c : str) {
        count[c]++;
    }
    return count;
}

int main() {
    // Test swap functions
    int a = 5, b = 10;
    swap1(a, b);
    std::cout << "Swap1: " << a << " " << b << "\n";
    
    a = 5, b = 10;
    swap2(a, b);
    std::cout << "Swap2: " << a << " " << b << "\n";
    
    a = 5, b = 10;
    swap3(a, b);
    std::cout << "Swap3: " << a << " " << b << "\n";

    // Test other functions...
    // ...
    
    return 0;
}
