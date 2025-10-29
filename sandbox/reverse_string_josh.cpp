#include <string>
#include <iostream>

void reverse_string(std::string& str) {
  std::cout << str << '\n'; 
  for (int i = 0; i < str.size() / 2; i++) {
    char tmp = str[i];
    str[i] = str[str.size()-1-i];
    str[str.size()-1-i] = tmp;
    std::cout << str << '\n'; 
  }
  std::cout << str << '\n'; 
}

int main() {
  std::string josh ("josh");
  std::string joshu ("joshu");
  reverse_string(josh);
  reverse_string(joshu);

  return 0;
}
