#include <iostream>  // for std::cout and std::cin

int main()
{
    std::cout << "Enter a number: "; // ask user for a number
    int x{}; // define variable x to hold user input
    std::cin >> x; // get number from keyboard and store it in variable x
    std::cout << "You entered " << x << '\n';

    std::cout << "Enter 3 numbers: "; // ask user for a number
    int y{}; // define variable x to hold user input
    int z{}; // define variable x to hold user input
    int w{}; // define variable x to hold user input
    std::cin >> y >> z >> w; // get number from keyboard and store it in variable x
    std::cout << "You entered " << y << ' ' << z << ' ' << w;

    return 0;
}
