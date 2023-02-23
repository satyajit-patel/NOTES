//https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
#include<bits/stdc++.h>
#define vvi vector<vector<int>>
#define vi vector<int>
bool f(int n, int target, vi &arr, vvi &dp) {
    if(target == 0) return true;
    if(n == 0) return target == arr[n];
    if(dp[n][target] != -1) return dp[n][target];
    
    bool notPick = f(n-1, target, arr, dp);
    bool pick = false;
    if(arr[n] <= target) pick = f(n-1, target-arr[n], arr, dp);
    return dp[n][target] = pick || notPick;
}
bool canPartition(vector<int> &arr, int n) {
	int sum = 0;
    for(auto &it : arr) sum += it;
    if(sum%2) return false;
    int k = sum/2;
    vvi dp(n+1, vi(k+1, -1));
    return f(n-1, k, arr, dp);
}
