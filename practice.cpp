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

int coin(vector<int> coin_list, int max) {
  // array to work with
  // 0 is 0
  // iterate through 1 to max, nested try all coins
  // check if coin is smaller
  // take min
  vector<int> dp(max + 1, max + 1);
  dp[0] = 0;

  for (int i = 1; i < size; i++) {  
    for (int j = 0; j < coin_list.size(); j++) {
      if (coin_list[j] < i)
        dp[i] = min(dp[i], dp[i - coin_list[j]] + 1); 
    }

int main() {
  return 0;
}
