// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/
class Solution {
public:
    int add(int x, int y) {
        int MOD = 1e9+7;
        return ((x%MOD) + (y%MOD))%MOD; 
    }

    int f(int n, int k, int target, vector<vector<int>>& dp) {
        // base case
        if(target < 0) return 0;
        if(n == 0) return target == 0;
        if(n!=0 && target==0) return 0;
        if(dp[n][target] != -1) return dp[n][target];
        
        // recursive case
        int summation = 0;
        for(int face=1; face<=k; face++) summation = add(summation, f(n-1, k, target-face, dp));

        // store and return
        dp[n][target] = summation;
        return summation;
    }

    int numRollsToTarget(int n, int k, int target) {
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(target+1, -1));
        return f(n, k, target, dp);
    }
};