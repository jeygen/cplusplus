// no rep knapsack
int knapSack(int W, vector<int>& wt, vector<int>& val) {
    int n = val.size();
    vector<vector<int>> K(n+1,vector<int>(W+1));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    return K[n][W];
}

int lcs(string& X, string& Y) { 
    int m = X.size();
    int n = Y.size();
    vector<vector<int>> L(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 
            if (i == 0 || j == 0) 
                L[i][j] = 0; 
            else if (X[i - 1] == Y[j - 1]) 
                L[i][j] = L[i - 1][j - 1] + 1; 
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
        } 
    } 

    return L[m][n]; 
} 

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

#include<bits/stdc++.h>
// INT_MIN is from <climits>
using namespace std;

int rodCutting(vector<int>& prices) {
    int n = prices.size();
    vector<int> dp(n+1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++) {
            max_val = max(max_val, prices[j] + dp[i-j-1]);
        }
        dp[i] = max_val;
    }

    return dp[n];
}

int main() {
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20}; // prices for lengths 1 to 8
    cout << "Max profit is " << rodCutting(prices) << endl;
    return 0;
}

