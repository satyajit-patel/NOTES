// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
class Solution {
public:
    int f(int W, int *wt, int *val, int n, vector<vector<int>>& dp, int i=0) {
        // base case
        if(i >= n) return 0;
        if(W <= 0) return 0;
        if(dp[i][W] != -1) return dp[i][W];
        
        // recursive case
        int incl = 0;
        if(wt[i] <= W) incl = val[i] + f(W - wt[i], wt, val, n, dp, i+1);
        int excl = 0 + f(W, wt, val, n, dp, i+1);
        int ans = std::max(incl, excl);
        
        // store and return
        dp[i][W] = ans;
        return ans;
    }

    int knapSack(int W, int wt[], int val[], int n) {
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        return f(W, wt, val, n, dp);
    }
};