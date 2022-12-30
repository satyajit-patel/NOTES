//https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
int f(int n, int W, vi &wt, vi &val, vvi &dp) {
    if(n == 0) {
        if(wt[n] <= W) return val[n];
        return 0;
    }
    if(dp[n][W] != -1) return dp[n][W];
    
    int notPick = 0 + f(n-1, W, wt, val, dp);
    int pick = int(-1e9);
    if(wt[n] <= W) {
        pick = val[n] + f(n-1, W-wt[n], wt, val, dp);
    }
    
    return dp[n][W] = max(pick, notPick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vvi dp(n+1, vi(maxWeight+1, -1));
    return f(n-1, maxWeight, weight, value, dp);
}