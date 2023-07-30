#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <queue>
#include <cctype>
#include <regex>
#include <set>
#include <climits>

using namespace std;

// fix this

v_P(string s) {
  std::stack stk{};
  for (char& c : string) {
    switch (c) {
      case '(':
        stk.push(')');
        break;
      case '{':
        stk.push(')');
        break;
      case '[':
        stk.push(']');
        break;
      case ')':
      case '}':
      case ']':
        stack.pop(c);
    }
    } 
      return stk.empty();
  }

int main() {
  return 0;
}
