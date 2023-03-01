// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// knapsack sign : atleast 1 array and a Capacity is given

class Solution {
public:
    int f(int W, int* wt, int* val, int n, vector<vector<int>>& dp, int i=0) {
        // base case
        if(i >= n) return 0;
        if(W <= 0) return 0;
        if(dp[i][W] != -1) return dp[i][W];
        
        // choice
        int include = 0, exclude = 0;
        if(wt[i] <= W) include = val[i] + f(W-wt[i], wt, val, n, dp, i+1);
        exclude = 0 + f(W, wt, val, n, dp, i+1);
        
        int optimal = std::max(include, exclude);
        dp[i][W]    = optimal;
        return optimal;
    }
    int knapSack(int W, int wt[], int val[], int n) {
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        return f(W, wt, val, n, dp);
    }
};