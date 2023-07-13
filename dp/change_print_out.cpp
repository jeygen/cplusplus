#include <vector>
#include <algorithm>
#include <iostream>

int coinChange(std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        std::cout << "i = " << i << std::endl; 
        for (long unsigned int j = 0; j < coins.size(); j++) {
            std::cout << "j = " << j << std::endl; 
            if (coins[j] <= i) {
                std::cout << "coins[j] = " << coins[j] << std::endl; 
                dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
                std::cout << "dp[i] = " << dp[i] << std::endl; 
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
  std::vector<int> coins = {1,5,6};
  int amount = 9;
  coinChange(coins, amount);
  return 0;
}
