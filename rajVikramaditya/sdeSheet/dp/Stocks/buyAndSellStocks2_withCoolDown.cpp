//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/
class Solution {
public:
    int f(int i, int n, int buy, vector<int> &val, vector<vector<int>> &dp) {
        //carefull here i+2 might go beyond N.... so do i >= n instead of i == n
        if(i >= n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        
        int profit = 0;
        if(buy) {
            int pick = -val[i] + f(i+1, n, !buy, val, dp);
            int notPick = 0 + f(i+1, n, buy, val, dp);
            profit = max(pick, notPick);
        }
        else {
            //we can't buy immediate aftre selling so we jump to next->next;
            int sell = val[i] + f(i+2, n, 1, val, dp);
            int notSell = 0 + f(i+1, n, 0, val, dp);
            profit = max(sell, notSell);
        }
        
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return f(0, n, 1, prices, dp);
    }
};