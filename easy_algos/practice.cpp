#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;

int l(const string& s) {
  char* c;
  c = s[0];
  int counter = 0;
  while (c* != nullptr) {
    c++;
    counter++; 
  }

  return counter;
}
  

int main(int argc, char** argv) {
  string s = "cat";
  cout << l(s) << endl;
  return 0;
}

