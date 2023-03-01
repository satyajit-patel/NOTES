// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{
public:
    int dp[1000+1][1000+1];
    int f(int i, int N, int* val) {
        // base case
        if(i >= N) return 0;
	if(N <= 0) return 0;
        if(dp[i][N] != -1) return dp[i][N];
        
        // recursive case
        int incl = 0;
        int cut  = i+1;
        if(cut <= N) incl = val[i] + f(i, N - cut, val);
        int excl = 0 + f(i+1, N, val);
        int optimal = std::max(incl, excl);
        
        // store and return
        dp[i][N] = optimal;
        return optimal;
    }
    int cutRod(int price[], int n) {
        std::memset(dp, -1, sizeof dp);
        return f(0, n, price);
    }
};