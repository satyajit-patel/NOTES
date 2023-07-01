// https://practice.geeksforgeeks.org/problems/coin-change2448/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    long long int dp[1000+1][1000+1];
    long long int f(int i, int W, int* wt, int N) {
        // base case
        if(i >= N) return W == 0;
        if(W < 0) return 0;
        if(dp[i][W] != -1) return dp[i][W];
        
        // recursive case
        long long int count =0;
        if(wt[i] <= W) count += f(i, W - wt[i], wt, N);
        count += f(i+1, W, wt, N);
        
        // store and return
        dp[i][W] = count;
        return count;
    }
    long long int count(int coins[], int N, int sum) {
        std::memset(dp, -1, sizeof dp);
        return f(0, sum, coins, N);
    }
};