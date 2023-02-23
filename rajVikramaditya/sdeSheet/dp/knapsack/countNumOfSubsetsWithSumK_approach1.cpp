//https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
#include <bits/stdc++.h>
#define vvi vector<vector<int>>
int f(int i, int n, int sum, int k, vector<int> &num, vvi &dp) {
    if(i == n) {
        if(sum == k) return 1;
        else return 0;
    }
    if(dp[i][sum] != -1) return dp[i][sum];
    
    sum += num[i];
    int pick = f(i+1, n, sum, k, num, dp);
    sum -= num[i];
    int notPick = f(i+1, n, sum, k, num, dp);
    return dp[i][sum] = pick + notPick;
}
int findWays(vector<int> &num, int tar) {
    int sum = 0;
    for(auto &it : num) sum += it;
    vvi dp(num.size()+1, vector<int>(sum+1, -1));
    return f(0, num.size(), 0, tar, num, dp);
}