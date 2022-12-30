//https://www.codingninjas.com/codestudio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h> 
#define vvi vector<vector<int>>
int dx[2] = {+1, +1};
int dy[2] = {0, +1};
int f(int i, int j, int n, vvi &triangle, vvi &dp) {
    if(i == n-1 && j < triangle[i].size()) return triangle[i][j];
    if(i >= n || j >= triangle[i].size()) return 1e9;
    if(dp[i][j] != -1) return dp[i][j];
    
    int minSum = INT_MAX, sum;
    for(int ind=0; ind<2; ind++) {
        int ni = i + dx[ind];
        int nj = j + dy[ind];
        sum = triangle[i][j] + f(ni, nj, n, triangle, dp);
        minSum = min(minSum, sum);
    }
    return dp[i][j] = minSum;
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
 	vvi dp(n+1, vector<int>(triangle[n-1].size()+1, -1));
	return f(0, 0, n, triangle, dp);
}