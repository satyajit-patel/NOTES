//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/submissions/
class Solution {
public:
    
    int f(int i, int n, int buy, vector<int> &val, vector<vector<int>> &dp, int fee) {
        if(i >= n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        
        int profit = 0;
        if(buy) {
            int pick = -val[i] + f(i+1, n, !buy, val, dp, fee);
            int notPick = 0 + f(i+1, n, buy, val, dp, fee);
            profit = max(pick, notPick);
        }
        else {
            //just pay the deliver charge here
            int sell = (val[i] - fee) + f(i+1, n, 1, val, dp, fee);
            int notSell = 0 + f(i+1, n, 0, val, dp, fee);
            profit = max(sell, notSell);
        }
        
        return dp[i][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return f(0, n, 1, prices, dp, fee);
    }
};