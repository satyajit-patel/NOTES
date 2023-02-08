// https://leetcode.com/problems/fibonacci-number/description/
class Solution {
public:
    int f(int n, vector<int>& dp) {
        // base case
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(dp[n] != -1) return dp[n];

        int prev     = f(n-1, dp);
        int prevPrev = f(n-2, dp);

        int ans = prev + prevPrev;
        dp[n]   = ans;
        return ans;
    }
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};