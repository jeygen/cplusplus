#include <iostream>

int fib(int n)
{
    if (n < 0) return -1;
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    std::cout << "Input length of series: ";
    std::cin >> n;
    std::cout << fib(n) << std::endl;
    return 0;
}

