//https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include <bits/stdc++.h> 
#define vi vector<int>
#define vvi vector<vector<int>>
int f(int n, int W, vi &wt, vi &val, vvi &dp) {
    if(n == 0) return ((W/wt[n]) * val[n]);
    if(dp[n][W] != -1) return dp[n][W];
    
    int notPick = 0 + f(n-1, W, wt, val, dp);
    int pick = INT_MIN;
    if(wt[n] <= W) pick = val[n] + f(n, W-wt[n], wt, val, dp);
    
    return dp[n][W] = max(pick, notPick);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
    vvi dp(n+1, vi(w+1, -1));
    return f(n-1, w, weight, profit, dp);
}
