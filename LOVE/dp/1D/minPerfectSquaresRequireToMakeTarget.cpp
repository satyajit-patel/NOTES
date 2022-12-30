//https://leetcode.com/problems/perfect-squares/
class Solution {
public:
    int f(int target, vector<int>& perfectS, vector<int>& dp) {
        //baseCase
        if(target == 0) return 0;
        if(target < 0) return 1e8;
        if(dp[target] != -1) return dp[target];
        
        int ans = 1e8;
        for(auto &it : perfectS) {
            ans = min(ans, 1 + f(target-it, perfectS, dp));
        }
        dp[target] = ans;
        return ans;
    }
    bool isPerfectSquare(int n) {
        int half = sqrt(n);
        return (half*half == n);
    }
    int numSquares(int n) {
        vector<int> perfectS;
        for(int i=1; i<=n; i++) {
            if(isPerfectSquare(i)) perfectS.push_back(i);
        }
        vector<int> dp(n+1, -1);
        return f(n, perfectS, dp);
    }
};