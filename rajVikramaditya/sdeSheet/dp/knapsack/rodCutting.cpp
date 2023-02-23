//https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
int f(int n, int length, vi &val, vvi &dp) {
    if(n == 0) return length * val[n];
    if(dp[n][length] != -1) return dp[n][length];
    
    int notPick = 0 + f(n-1, length, val, dp);
    int pick = INT_MIN;
    int rodLen = n+1;
    if(rodLen <= length) pick = val[n] + f(n, length-rodLen, val, dp);
    
    return dp[n][length] = max(pick, notPick);
}
int cutRod(vector<int> &price, int n) {
    vvi dp(n+1, vi(n+1, -1));
    return f(n-1, n, price, dp);
}
