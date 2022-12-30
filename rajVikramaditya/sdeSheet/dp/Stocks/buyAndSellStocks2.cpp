//https://www.codingninjas.com/codestudio/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include<bits/stdc++.h>
#define vvi vector<vector<long>>
long f(int i, int n, int canWeBuy, long *val, vvi &dp) {
    if(i == n) return 0;
    if(dp[i][canWeBuy] != -1) return dp[i][canWeBuy];
    
    long profit = 0;
    if(canWeBuy) {
        long buy = -val[i] + f(i+1, n, !canWeBuy, val, dp);
        long notBuy = 0 + f(i+1, n, canWeBuy, val, dp);
        profit = max(buy, notBuy);
    }
    else {
        long sell = val[i] + f(i+1, n, 1, val, dp);
        long notSell = 0 + f(i+1, n, 0, val, dp);
        profit = max(sell, notSell);
    }
    return dp[i][canWeBuy] = profit;
}
long getMaximumProfit(long *values, int n) {
    //make the dp of changing paremetres only
    vvi dp(n+1, vector<long>(2, -1));
    return f(0, n, 1, values, dp);
}