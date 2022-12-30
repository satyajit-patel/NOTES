//https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?leftPanelTab=1
#include <bits/stdc++.h> 
#define vvi vector<vector<int>>
int dx[2] = {0, -1};
int dy[2] = {-1, 0};
int f(int n, int m, vvi &grid, vvi &dp) {
    if(n == 0 && m == 0) return grid[n][m];
    if(n < 0 || m <0) return 1e9;
    if(dp[n][m] != -1) return dp[n][m];
    
    int minSum = INT_MAX, sum;
    for(int ind=0; ind<2; ind++) {
        int ni = n + dx[ind];
        int nj = m + dy[ind];
        sum = grid[n][m] + f(ni, nj, grid, dp);
        minSum = min(minSum, sum);
    }
    return dp[n][m] = minSum;
}
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vvi dp(n+1, vector<int>(m+1, -1));
    return f(n-1, m-1, grid, dp);
}