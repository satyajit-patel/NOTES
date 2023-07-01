// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{
public:
    int dp[1000+1][1000+1];
    int f(int i, int W, int* wt, int* val) {
        // base case
        if(i >= W) return 0;
        if(W <= 0) return 0;
        if(dp[i][W] != -1) return dp[i][W];
        
        // recursive case
        int incl = 0;
        if(wt[i] <= W) incl = val[i] + f(i, W - wt[i], wt, val);
        int excl = 0 + f(i+1, W, wt, val);
        int optimal = std::max(incl, excl);
        
        // store and return
        dp[i][W] = optimal;
        return optimal;
    }
    int cutRod(int price[], int n) {
        std::memset(dp, -1, sizeof dp);
        int wt[n];
        for(int i=0; i<n; i++) wt[i] = i+1; // becz 0 cut doesn't make sence
        return f(0, n, wt, price);
    }
};