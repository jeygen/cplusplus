You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.



int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }
    
    int maxProfit = 0; // Initialize maxProfit to 0, since the minimum profit you can have is 0 (i.e., not making any transaction).
    int minPrice = prices[0]; // Initialize minPrice to the first price.
    
    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] < minPrice) { // If the current price is less than minPrice, update minPrice.
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) { // Else, calculate potential profit and update maxProfit if it's greater than the previous maxProfit.
            maxProfit = prices[i] - minPrice;
        }
    }
    
    return maxProfit;
}

