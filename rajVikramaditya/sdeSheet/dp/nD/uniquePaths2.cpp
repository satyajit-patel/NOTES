//https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>
#define vvi vector<vector<int>>
int M = int(1e9 + 7);
int dx[2] = {0, -1};
int dy[2] = {-1, 0};
int f(int n, int m, vvi &dp, vvi &mat) {
    if(n == 0 && m == 0) return 1;
    if(n < 0 || m < 0 || mat[n][m] == -1) return 0;
    if(dp[n][m] != -1) return dp[n][m];

    int count = 0;
    for(int ind=0; ind<2; ind++) {
        int ni = n + dx[ind];
        int nj = m + dy[ind];
        count += f(ni, nj, dp, mat);
    }
    return dp[n][m] = (count) % M;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return f(n-1, m-1, dp, mat);
}