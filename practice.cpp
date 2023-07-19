#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <queue>
#include <cctype>
#include <regex>
#include <set>

bool P(string s) {
  std::vector<int> cleaned_s;
  for(char c : s) {
    if (c > 47 && c < 123) {
      cleaned_s.push_back(c);
    }
  }

  for (int i = 0; i < cleaned_s.size()/2; i++) {
    if (cleaned_s[i] != cleaned_s[cleaned_s.size() - 1 -i]) {
      return false;
    }
  }

  return true;
}
