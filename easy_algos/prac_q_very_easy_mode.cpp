// swap at least 3 ways
// fibo 
// factorial
// binary search
// reverse string
// fizzbuzz
// bubble sorto
// count chars in string
// Palindrome Checker
// Prime Number Checker
// Count number of digits in integer
// Reverse an integer
// Array Sum
// Find Minimum/Maximum
// String Length without using `length()` or `size()`
// Odd or Even

// Convert Case
// Duplicate Element Checker
// Vowel Counter
// Multiplication Table
// Find the missing number
// Find the duplicate number
// Remove duplicates from a list

// dot product
// matrix mult
// matrix add

// Levenshtein distance


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
    if (n < 0) {
        std::cerr << "Error: Fibonacci is not defined for negative numbers." << std::endl;
        return -1;
    }
    else if (n <= 1) return n;
    else return fibonacci(n-1) + fibonacci(n-2);
}

// Factorial
int factorial(int n) {
    if (n < 0) {
        std::cerr << "Error: Factorial is not defined for negative numbers." << std::endl;
        return -1;
    }
    else if (n <= 1) return 1;
    else return n * factorial(n - 1);
}


// Binary Search
// return the index of target
int binary_search(int a[], int l, int r, int target) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle itself
        if (a[mid] == target)
            return mid;

        // If the element is smaller than mid, then it can only be present in the left subarray
        if (a[mid] > target)
            return binary_search(a, l, mid - 1, target);

        // Else, the element can only be present in the right subarray
        return binary_search(a, mid + 1, r, target);
    }

    // We reach here when the element is not present in the array
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

std::string rev_string(std::string& s) {
	int mid = s.length() / 2;
	for (int i=0; i < mid; i++) {
		std::swap(s[i], s[s.length()-1-i]);
	}
	return s
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

#include <unordered_map>

std::unordered_map<char, int> count_chars(const std::string& str) {
    std::unordered_map<char, int> count;
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

// palindrome
// template< class ExecutionPolicy, class ForwardIt1, class ForwardIt2 >
bool is_palindrome(const std::string& s) {
    return std::equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}

// prime
bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int array_sum(int arr[], int n) {
    int sum = 0;
    for(int i=0; i<n; i++) sum += arr[i];
    return sum;
}

int string_length(const char* str) {
    const char *s = str;
    while(*s) ++s;
    return s - str;
}


