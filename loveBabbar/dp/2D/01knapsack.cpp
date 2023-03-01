//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
class Solution {
    public:
    int f(int i, int n, int W, int* val, int* wt, vector<vector<int>>& dp) {
        //baseCase
        if(i == n) return 0;
        if(W <= 0) return 0;
        if(dp[i][W] != -1) return dp[i][W];
        
        //include
        int incl = 0;
        if(wt[i] <= W) incl = val[i] + f(i+1, n, W-wt[i], val, wt, dp);
        
        //exclude
        int excl = 0 + f(i+1, n, W, val, wt, dp);
        
        int ans = max(incl, excl);
        dp[i][W] = ans;
        return ans;
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) {
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        return f(0, n, W, val, wt, dp);
    }
};