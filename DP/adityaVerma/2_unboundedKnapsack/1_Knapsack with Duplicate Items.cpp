// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{
public:
    int dp[1000+1][1000+1];
    int f(int i, int W, int* wt, int* val, int N) {
        // base case
        if(i >= N) return 0;
        if(W <= 0) return 0;
        if(dp[i][W] != -1) return dp[i][W];
        
        // recursive case
        int include = 0, exclude = 0;
        if(wt[i] <= W) include = val[i] + f(i, W - wt[i], wt, val, N);
        exclude = 0 + f(i+1, W, wt, val, N);
        int optimal = std::max(include, exclude);
        
        // store and return
        dp[i][W] = optimal;
        return optimal;
    }
    int knapSack(int N, int W, int val[], int wt[]) {
        std::memset(dp, -1, sizeof dp);
        return f(0, W, wt, val, N);
    }
};