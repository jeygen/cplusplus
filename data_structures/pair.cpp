// Pair is in the <utility> header

// pair <data_type1, data_type2> Pair_name;

#include<iostream>
#include<utility>

int main()
{
	std::pair <int, char> PAIR1; 
	PAIR1.first = 100; 
	PAIR1.second = 'G'; 

	std::cout << PAIR1.first << " ";
	std::cout << PAIR1.second << std::endl;

	return 0;
}

// another example
/* 
  std::queue<std::pair<int, int>> q;
  q.push({sr, sc});
  // this initializes x and y into their own vars
  // structured binding, it is shorthand for int x = q.front().first, y =
  // q.front().second
  auto [x, y] = q.front();
*/

#include <utility> // Include for std::pair

int main() {
    // Creating pairs
    std::pair<int, char> p1; // Default constructor, elements are default initialized
    std::pair<int, char> p2(1, 'a'); // Initialize with two values
    std::pair<int, char> p3 = {2, 'b'}; // Initialize with brace-enclosed list
    std::pair<int, char> p4(p2); // Copy constructor
    std::pair<int, char> p5(std::move(p4)); // Move constructor

    // Accessing elements
    int i = p2.first; // Access first element
    char c = p2.second; // Access second element

    // Using operations
    p1 = p2; // Assignment operator, copies contents from p2 to p1
    p1.swap(p2); // Swaps contents of p1 and p2

    // Comparisons
    bool eq = p1 == p2; // Checks if p1 and p2 are equal
    bool neq = p1 != p2; // Checks if p1 and p2 are not equal
    bool lt = p1 < p2; // Checks if p1 is lexicographically less than p2
    bool gt = p1 > p2; // Checks if p1 is lexicographically greater than p2
    bool lte = p1 <= p2; // Checks if p1 is lexicographically less than or equal to p2
    bool gte = p1 >= p2; // Checks if p1 is lexicographically greater than or equal to p2

    // Additional utility functions
    std::pair<int, char> p6 = std::make_pair(3, 'c'); // Makes a pair without having to write the types explicitly
}
  
// another example

std::pair<int, int> divide(int numerator, int denominator) {
    if(denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }

    int quotient = numerator / denominator;
    int remainder = numerator % denominator;
    
    return std::make_pair(quotient, remainder);
}
