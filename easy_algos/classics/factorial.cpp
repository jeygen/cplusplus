#include <iostream>

int fact(int n) {
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

int main()
{
    int n;
    std::cout << "Input n!: ";
    std::cin >> n;
    std::cout << fact(n) << std::endl;
    return 0;
}

