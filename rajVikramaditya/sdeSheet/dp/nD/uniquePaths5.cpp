//https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include <bits/stdc++.h> 
#define vvi vector<vector<int>>
int dx[3] = {-1, -1, -1};
int dy[3] = {0, -1, +1};
int f(int n, int m, vvi &matrix, vvi &dp) {
    if(n == 0 && m < matrix[n].size() && m >= 0) return matrix[n][m];
    if(n < 0 || n >= matrix.size() || m < 0 || m >= matrix[n].size()) return int(-1e9);
    if(dp[n][m] != -1) return dp[n][m];
    
    int maxSum = int(-1e9), sum;
    for(int ind=0; ind<3; ind++) {
        int ni = n + dx[ind];
        int nj = m + dy[ind];
        sum = matrix[n][m] + f(ni, nj, matrix, dp);
        maxSum = max(maxSum, sum);
    }
    return dp[n][m] = maxSum;
}
int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vvi dp(n+1, vector<int>(m+1, -1));
    int maxi = int(-1e9);
    for(int j=m-1; j>=0; j--) {
        maxi = max(maxi, f(n-1, j, matrix, dp));
    }
    return maxi;
}