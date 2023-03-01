// https://practice.geeksforgeeks.org/problems/number-of-coins1824/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{
public:
    int dp[1000+1][1000+1];
    int f(int i, int W, int* wt, int N) {
        // base case
        if(i >= N) {
            if(W == 0) return 0;
            return 1e9;
        }
        if(W < 0) return 1e9;
        if(dp[i][W] != -1) return dp[i][W];
        
        // recursive case
        int incl = 1e9;
        if(wt[i] <= W) incl = 1 + f(i, W - wt[i], wt, N);
        int excl = 0 + f(i+1, W, wt, N);
        int optimal = std::min(incl, excl);
        
        // store and return
        dp[i][W] = optimal;
        return optimal;
    }
	int minCoins(int coins[], int M, int V) {
	    std::memset(dp, -1, sizeof dp);
	    int ans = f(0, V, coins, M);
	    if(ans >= 1e9) return -1;
	    return ans;
	} 
};