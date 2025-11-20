#include <iostream>
#include <cmath>

int main() {
    int num = 12345;

    int count = num > 0 ? (int)log10(num) + 1 : 1;

    std::cout << "Number of digits: " << count << std::endl;

    return 0;
}
