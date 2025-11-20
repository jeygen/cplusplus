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
// Count number of digits in integer and reverse
// Array Sum
// Find Minimum/Maximum
// String Length without using `length()` or `size()`
// Odd or Even

boolean is_prime(int n) {
  if (n <= 1) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 3; i * i < n; i+=2) {
    if (n % i == 0) return true;
  }
  return false;
}




// Convert Case
// Duplicate Element Checker
// Vowel Counter
// Multiplication Table
// Find the missing number
// Find the duplicate number
// Remove duplicates from a list

// dot product
// cross product
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
        int mid = l + (r - l) / 2; // floor + current mid of indices

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

int binarySearch(vector<int>& arr, int key) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;  // return -1 if the key is not found
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

void count_n_reverse(int n) {
    std::queue<int> s; 
    int num_of_digits = 0;  
    while (n != 0) {          
        s.push(n % 10);         
        n /= 10;                
        num_of_digits++;    
    }                     
    std::cout << num_of_digits << "\n";
    n = 0; // reset n
    while (!s.empty()) {          
        n += s.front() * pow(10, num_of_digits--);
        s.pop();  // Pop the value after using it
    }                                 
    std::cout << n << "\n";            
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

def bubble_sort(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

// count chars 

#include <unordered_map>

std::unordered_map<char, int> count_chars(const std::string& str) {
    std::unordered_map<char, int> count;
    for (char c : str) {
        count[c]++;
    }
    return count;
}

size_t count_chars(const std::string& str) {
    size_t count = 0;
    const char* ptr = str.c_str();  // Get a pointer to the start of the string
    while(*ptr) {  // Loop until we hit the null-terminating character
        count++;
        ptr++;  // Move the pointer to the next character
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

// duplicates
my_list = [1, 2, 2, 3, 4, 4, 4, 5]
my_set = set(my_list)
print(my_set)


// Vector is represented using std::array of 3 elements
using Vector = std::array<double, 3>;

// Matrix is represented using std::array of std::array (essentially, 2D array) of 3x3 elements
using Matrix = std::array<std::array<double, 3>, 3>;

// Dot product
double dotProduct(const Vector& a, const Vector& b) {
    return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}

// Cross product
Vector crossProduct(const Vector& a, const Vector& b) {
    return {a[1]*b[2] - a[2]*b[1], a[2]*b[0] - a[0]*b[2], a[0]*b[1] - a[1]*b[0]};
}

// Matrix multiplication
Matrix matrixMultiply(const Matrix& a, const Matrix& b) {
    Matrix result = {};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

// Matrix addition
Matrix matrixAdd(const Matrix& a, const Matrix& b) {
    Matrix result = {};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

