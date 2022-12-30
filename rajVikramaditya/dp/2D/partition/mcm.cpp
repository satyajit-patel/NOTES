#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
#define endl "\n"

vi arr;
int mcm(int i, int j, vii &dp) {
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int mini = INT_MAX;   
    for(int k=i; k<j; k++) {
        int leftPartition = mcm(i, k, dp);
        int rightPartition = mcm(k+1, j, dp);
        int cost = (arr[i-1]*arr[j])*arr[k];
        mini = min(leftPartition + rightPartition + cost, mini);
    }
    return dp[i][j] = mini;
}
int main() {
    int n; cin>>n;
    arr.resize(n);
    vii dp(n+1, vi(n+1, -1));
    for(auto &it:arr) cin>>it;
    cout<<mcm(1, n-1, dp);
    return 0;
}