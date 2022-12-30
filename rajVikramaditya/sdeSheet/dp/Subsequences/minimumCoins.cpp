//https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=1
#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
int f(int n, int target, vi &num, vvi &dp) {
    if(n == 0) {
        if(target%num[n] == 0) return target/num[n];
        else return int(1e9);
        /*
            because INT_MAX > 1e9
            so suppose we had target left = 4(anythig) and
            if we returned INT_MAX then INT_MAX + 4 would definately go
            beyond int limit and will give overflow..
            so we rather return somethig big i.e 1e9 which is not entierly big.
        */
    }
    if(dp[n][target] != -1) return dp[n][target];
    
    int notPick = 0 + f(n-1, target, num, dp);
    int pick = INT_MAX;
    if(num[n] <= target) pick = 1 + f(n, target-num[n], num, dp);
    
    return dp[n][target] = min(pick, notPick);
}
int minimumElements(vector<int> &num, int x) {
    int n = num.size();
    vvi dp(n+1, vi(x+1, -1));
    int ans = f(n-1, x, num, dp);
    if(ans >= int(1e9)) return -1;
    return ans;
}