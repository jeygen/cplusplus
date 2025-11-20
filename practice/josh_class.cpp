#include <iostream>
#include <string>

class Josh {
private:
  std::string name = "josh";
public:
  int age {};

  Josh(int age) : age(age) {}

  void print_name() {
    std::cout << name << '\n';
  }
};

int main() {
  Josh j(3);
  j.print_name();

  return 0;
}


