#include <iostream>

int main()
{
  char x{};
  int y{};
  y = x;
  std::cout << "Input a char: ";
  std::cin >> x;
  std::cout << "as char: " << x << '\n';
  std::cout << "as int, implicit: " << y << '\n';
  std::cout << "as int, explicit: " << static_cast<int>(x) << '\n';
  return 0;
}
