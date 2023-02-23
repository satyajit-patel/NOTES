//https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include<bits/stdc++.h>
long int f(int n, int target, int *a, vector<vector<long int>> &dp) {
    if(n == 0) return (target%a[n] == 0);
    if(dp[n][target] != -1) return dp[n][target];
    
    long int notPick = f(n-1, target, a, dp);
    long int pick = 0;
    if(a[n] <= target) pick = f(n, target-a[n], a, dp);
    
    return dp[n][target] = (pick + notPick);
}
long countWaysToMakeChange(int *denominations, int n, int value) {
    vector<vector<long int>> dp(n+1, vector<long int>(value+1, -1));
    return f(n-1, value, denominations, dp);
}