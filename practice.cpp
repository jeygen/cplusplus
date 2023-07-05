#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <queue>
#include <cctype>
#include <regex>
#include <set>

bool containsDuplicate(vector<int>& nums) {
  std::unordered_set<int> us{};
  for (int e : us) {
    if (us.find(e) != us.end) {
      return true;
    }
    us.push_back(e);
  } 
  return false;
}
   
int main(int argc, char** argv) {
}
