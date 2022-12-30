//https://bit.ly/3JPcoOx
#include <bits/stdc++.h> 
int fj(int n, vector<int> &heights, vector<int> &dp) {
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    
    int left = abs(heights[n]-heights[n-1]) + fj(n-1, heights, dp);
    int right = INT_MAX;
    if(n-2 >= 0) right = abs(heights[n]-heights[n-2]) + fj(n-2, heights, dp);
    return dp[n] = min(left, right);
}
int frogJump(int n, vector<int> &heights) {
    
//     vector<int> dp(n+1, -1);
//     return fj(n-1, heights, dp);

    vector<int> dp(n);
    dp[0] = 0;
    for(int i=1; i<n; i++) {
        int left = abs(heights[i]-heights[i-1]) + dp[i-1];
        int right = INT_MAX;
        if(i-2 >= 0) right = abs(heights[i]-heights[i-2]) + dp[i-2];
        dp[i] = min(left, right);
    }    
    return dp[n-1];
}