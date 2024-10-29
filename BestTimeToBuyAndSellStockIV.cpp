// Companies asking this question: Adobe, Razorpay, OYO, Visa, Salesforce, Groww, Phone Pe, Oracle, Amazon, Hotstar, D.E.Shaw

/*****************************************************************************************
Problem statement
You have been given an array 'PRICES' consisting of 'N' integers where PRICES[i] denotes the price of a given stock on the i-th day. You are also given an integer 'K' denoting the number of possible transactions you can make.

Your task is to find the maximum profit in at most K transactions. A valid transaction involves buying a stock and then selling it.

Note
You can’t engage in multiple transactions simultaneously, i.e. you must sell the stock before rebuying it.
For Example
Input: N = 6 , PRICES = [3, 2, 6, 5, 0, 3] and K = 2.
Output: 7

Explanation : The optimal way to get maximum profit is to buy the stock on day 2(price = 2) and sell it on day 3(price = 6) and rebuy it on day 5(price = 0) and sell it on day 6(price = 3). The maximum profit will be (6 - 2) + (3 - 0) = 7.
Detailed explanation ( Input/output format, Notes, Images )
Constraints
1 <= T <= 100
1 <= N <= 5000
0 <= K <= N/2
0 <= ARR[i] <=10^5

Time Limit : 1 sec
Sample Input 1
2
5 2
8 5 1 3 10
4 2
10 8 6 2 
Sample Output 1
9
0
Explanation for Sample 1
Test Case 1: In this case, we can make a maximum of 2 transactions. The optimal way to get maximum profit is to make only 1 transaction, i.e., buy the stock on day 3 (price = 1) and sell it on day 5(price = 10). The profit will be 10 - 1 = 9.

Test Case 2: In the second test case, we can make a maximum of 2 transactions. The optimal way to get maximum profit is to make 0 transactions because the price of stock is continuously decreasing and we will have a loss if we buy and sell the stock.
Sample Input 2
2
4 0
2 6 5 2
4 2
1 2 3 5
Sample Output 2
0
4
*****************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices, int n, int k) {
    if (n == 0 || k == 0) return 0;

    if (k >= n / 2) {
        int maxProfit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }

    vector<vector<int>> dp(k + 1, vector<int>(n, 0));

    for (int i = 1; i <= k; i++) {
        int maxDiff = -prices[0];
        for (int j = 1; j < n; j++) {
            dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
            maxDiff = max(maxDiff, dp[i - 1][j] - prices[j]);
        }
    }

    return dp[k][n - 1];
}
