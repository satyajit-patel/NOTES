//https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0
#include <bits/stdc++.h>
#define vvi vector<vector<int>>
bool f(int n, int target, vector<int> &arr, vvi &dp) {
    if(target == 0) return true;
    if(n == 0) return (target == arr[n]);
    if(dp[n][target] != -1) return dp[n][target];
    
    bool notPick = f(n-1, target, arr, dp);
    bool pick = false;
    if(arr[n] <= target) pick = f(n-1, target-arr[n], arr, dp);
    return dp[n][target] = pick || notPick;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vvi dp(n+1, vector<int>(k+1, -1));
    return f(n-1, k, arr, dp);
}