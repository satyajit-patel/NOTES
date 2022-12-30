//https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include <bits/stdc++.h> 
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
int dy[3] = {-1, 0, +1};
int f(int i, int j1, int j2, vvi &grid, vvvi &dp, int n, int m) {
    if(i >= n || j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return int(-1e9);
    if(i == n-1) {
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    
    int maxSum = int(-1e9);
    for(int ind1=0; ind1<3; ind1++) {
        for(int ind2=0; ind2<3; ind2++) {
            int nj1 = j1 + dy[ind1];
            int nj2 = j2 + dy[ind2];
            int sum = 0;
            if(nj1 == nj2) sum += grid[i][j1];
            else sum += grid[i][j1] + grid[i][j2];
            sum += f(i+1, nj1, nj2, grid, dp, n, m);
            maxSum = max(maxSum, sum);
        }
    }
    return dp[i][j1][j2] = maxSum;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vvvi dp(r+1, vvi(c+1, vector<int>(c+1, -1)));
    return f(0, 0, c-1, grid, dp, r, c);
}