// https://leetcode.com/problems/n-th-tribonacci-number/submissions/
class Solution {
public:
    int f(int n, vector<int>& dp) {
        //base case
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;
        if(dp[n] != -1) return dp[n];

        int prev0   = f(n-1, dp);
        int prev1   = f(n-2, dp);
        int prev2   = f(n-3, dp);

        int ans = prev0 + prev1 + prev2;
        dp[n] = ans;
        return ans;
    }
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};