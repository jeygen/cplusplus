#include <iostream>
#include <cstdlib>

// using unit32_t is dumb, as you can crash it by neg cin

uint32_t fibonacci(uint32_t n) {
	if (n < 0) return -1;
    if (n == 1 || n == 0) {
        return n;
    }
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    uint32_t n;
	std::cout << "\nINPUT NUM: " << std::endl;
	std::cin >> n;
    
    // Print the Fibonacci series
    for (uint32_t i = 0; i < n; i++) {
        std::cout << fibonacci(i) << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

