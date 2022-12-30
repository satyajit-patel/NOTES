//https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

#include <bits/stdc++.h>
#define vvi vector<vector<int>>
int M = int(1e9+7);
int f(int n, int target, vector<int> &arr, vvi &dp) {
    if(n == 0){
        if(target==0 && arr[n]==0)
            return 2;
        if(target==0 || target==arr[0])
            return 1;
        return 0;
    }
    if(dp[n][target] != -1) return dp[n][target];
    
    int notPick = f(n-1, target, arr, dp);
    int pick = 0;
    if(arr[n] <= target) pick = f(n-1, target-arr[n], arr, dp);
    
    return dp[n][target] = (pick + notPick)%M;
}
int countPartitions(int n, int d, vector<int> &arr) {
    /*
        totSum = s1 + s2
        s1 = totSum - s2 ----------. eqn 1
        i.e we are looking for
        => s1 - s2 == d
        => (totSum - s2) - s2 = d ----------- from eqn 1
        => totSum - d = 2 * s2
        => s2 = (totSum - d)/2 -------> becoms our target
    */
    int totSum = 0;
    for(auto &it : arr) totSum += it;
    if(totSum-d < 0 || (totSum-d)%2) return 0;
    int s2 = (totSum - d)/2;
    vvi dp(n+1, vector<int>(s2+1, -1));
    
    return f(n-1, s2, arr, dp);
}


