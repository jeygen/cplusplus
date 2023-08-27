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

// practice here 

  int majorityElement(vector<int>& nums) {
    int trigger = nums.size() / 2;
    unordered_map<int, int> um;
    for (auto& e : nums) {
      um[e]++;
      if (um[e] == trigger)
          return um[e];
    }
    return -1;
  }

int main() {
  return 0;
}
