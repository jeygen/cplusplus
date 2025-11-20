#include <iostream>
#include <iomanip>

int main() {
  std::cout << "0xe + 0x1" << '\n';
  std::cout << std::hex << 0xe + 0x1 << '\n';
  std::cout << std::showbase << std::hex << 0xe + 0x1 << '\n';

  // need  iomanip // this isn't quite right
  std::cout << std::setfill('0') << std::setw(10) << std::showbase << std::hex << 5 << '\n';
  return 0;
}
