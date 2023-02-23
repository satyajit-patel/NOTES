//https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h>
#define vvi vector<vector<int>>

int f(int n, int target, vector<int> &num, vvi &dp) {
    if(n == 0) {
        if(target == 0 && num[n] == 0) return 2;
        return (target == 0 || target == num[n]);
    }
    if(dp[n][target] != -1) return dp[n][target];
    
    int notPick = f(n-1, target, num, dp);
    int pick = 0;
    if(num[n] <= target) pick = f(n-1, target-num[n], num, dp);
    
    return dp[n][target] = pick + notPick;
}
int findWays(vector<int> &num, int tar) {
    int n = num.size();
    vvi dp(n+1, vector<int>(tar+1, -1));
    return f(n-1, tar, num, dp);
}