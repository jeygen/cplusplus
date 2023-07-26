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

int coin(vector<int> coin_list, int max) {
  // dp array, initialized to a lil bigger than fully needed
  // nested loop for size and want to cycle through each coin value
  // take min 
  vector<int> dp(max + 1, max + 1);
  dp[0] = 0;
  for (int i = 1; i <= max; i++) {
    for (int j = 0; j <= coin_list.size(); j++) {
      if (coin_list[j] < dp[i]) {
        dp[i] = min(dp[i], dp[i - coin_list[j]] + 1);
      }
    }
  }
}



int main() {
  return 0;
}
