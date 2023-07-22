#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <queue>
#include <cctype>
#include <regex>
#include <set>

bool contains_d(std::vector<int>& nums) {
  // could use set but ordererd or unordered?
  // // order doesn't matter in this context
  std::unordered_set us{};
  for (auto& n : nums) {
    if (us.find(n)) {return false;}
    us.push_back(n);
  }

  return true;

