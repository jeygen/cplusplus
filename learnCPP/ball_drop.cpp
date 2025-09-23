#include<iostream>

// func1 for userinput
// func2 do math of ball
// fallen = gravity_constant * x_seconds2 / 2

double get_height()
{
  double h{};
  std::cout << "Input ball height: ";
  std::cin >> h;
  return h;
}  

void print_height(double h)
{
  if (h <= 0)
    std::cout << "\nball at ground.\n";
  std::cout << "\nat 0 sec: " << h; 
  std::cout << "\nat 1 sec: " << h - 9.8 * 1 / 2; 
  if (h <= 0)
    std::cout << "ball at ground.\n";
  std::cout << "\nat 2 sec: \n" << h - 9.8 * 2*2 / 2; 
  if (h <= 0)
    std::cout << "ball at ground.\n";
  std::cout << "\nat 3 sec: \n" << h - 9.8 * 3*2 / 2; 
  if (h <= 0)
    std::cout << "ball at ground.\n";
  std::cout << "\nat 4 sec: \n" << h - 9.8 * 4*2 / 2; 
  if (h <= 0)
    std::cout << "ball at ground.\n";
  std::cout << "\nat 5 sec: " << h - 9.8 * 5*2 / 2; 
  if (h <= 0)
    std::cout << "\nball at ground.\n";
}

int main() 
{
  double h{};
  h = get_height();
  print_height(h);
  return 0;
}


