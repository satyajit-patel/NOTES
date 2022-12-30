//https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include <bits/stdc++.h> 
bool f(int n, int target, vector<int> &arr, vector<vector<int>> &dp) {
    if(target == 0) return true;
    if(n == 0) return arr[0] == target;
    if(dp[n][target] != -1) return dp[n][target];
    
    bool notTake = f(n-1, target, arr, dp);
    bool take = false;
    if(arr[n] <= target) take = f(n-1, target-arr[n], arr, dp);
    return dp[n][target] = take || notTake;
}
int minSubsetSumDifference(vector<int>& arr, int n) {
	int totalSum = 0;
    for(auto &it : arr) totalSum += it;
    vector<vector<int>> dp(n+1, vector<int>(totalSum+1, -1));
    vector<int> s1;
    vector<int> s2;
    for(int i=0; i<=totalSum; i++) {
        if(f(n-1, i, arr, dp)) {
            s1.push_back(i);
            s2.push_back(abs(i - totalSum));
        }
    }
    int minDiff = INT_MAX;
    for(int i=0; i<s1.size(); i++) {
        int diff = abs(s1[i] - s2[i]);
        if(diff < minDiff) minDiff = diff;
    }
    return minDiff;
}
