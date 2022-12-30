//https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
int mcm(int i, int j, vi &a, vvi &dp) {
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int mini = INT_MAX, step;
    for(int k=i; k<j; k++) {
        step = mcm(i, k, a, dp) + mcm(k+1, j, a, dp) + (a[i-1] * a[j]) * a[k];
        mini = min(mini, step);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N) {
    vvi dp(N+1, vi(N+1, -1));
    return mcm(1, N-1, arr, dp);
}