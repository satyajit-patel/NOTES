//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/
class Solution {
public:
    int f(int i, int n, int canBuy, int cap, vector<int> &val, vector<vector<vector<int>>> &dp) {
        if(i == n) return 0;
        if(cap == 0) return 0;
        if(dp[i][canBuy][cap] != -1) return dp[i][canBuy][cap];
        
        int profit = 0;
        if(canBuy) {
            int buy = -val[i] + f(i+1, n, !canBuy, cap, val, dp);
            int notBuy = 0 + f(i+1, n, canBuy, cap, val, dp);
            profit = max(buy, notBuy);
        }
        else {
            int sell = val[i] + f(i+1, n, 1, cap-1, val, dp);
            int notSell = 0 + f(i+1, n, 0, cap, val, dp);
            profit = max(sell, notSell);
        }
        
        return dp[i][canBuy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        //tc ---> O(N * 2 * 3);
        return f(0, n, 1, 2, prices, dp);
    }
};