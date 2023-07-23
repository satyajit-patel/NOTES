// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/
class Solution {
private:
    int k;
    int add(int a, int b) {
        int const MOD = 1e9 + 7;
        return ((a % MOD) + (b % MOD)) % MOD;
    }

    std::vector<std::vector<int>> dp;
    int f(int n, int target) {
        // base case
        if(target < 0) return 0;
        if(n == 0) return target == 0;
        if(dp[n][target] != -1) return dp[n][target];

        // recursive case
        int ways = 0;
        for(int face=1; face<=this->k; face++) ways = add(ways, f(n-1, target-face));
        
        // return case
        dp[n][target] = ways;
        return ways;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        this->k = k;
        dp.resize(n+1, std::vector<int>(target+1, -1));
        return f(n, target);
    }
};