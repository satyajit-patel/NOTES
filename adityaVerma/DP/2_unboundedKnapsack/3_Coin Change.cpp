// https://practice.geeksforgeeks.org/problems/coin-change2448/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    long long int dp[1000+1][1000+1];
    long long int f(int i, int sum, int* coins, int N) {
        // base case
        if(i >= N) return sum == 0;
        if(sum < 0) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        
        // recursive case
        long long int incl =0;
        if(coins[i] <= sum) incl = f(i, sum - coins[i], coins, N);
        long long int excl = f(i+1, sum, coins, N);
        long long int optimal = incl + excl;
        
        // store and return
        dp[i][sum] = optimal;
        return optimal;
    }
    long long int count(int coins[], int N, int sum) {
        std::memset(dp, -1, sizeof dp);
        return f(0, sum, coins, N);
    }
};