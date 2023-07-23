// https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/description/
class Solution {
public:
    long long p, MOD = 1e9+7, dp[300+4][300+4];

    int my_pow(int base, int power) {
        int ans = 1;
        while(power) {
            if(power&1) ans = ((ans%MOD) * (base%MOD)) % MOD;
            base = ((base%MOD) * (base%MOD)) % MOD;
            power >>= 1;
        }
        return ans;
    }

    long long f(long long n, long long base) {
        // base case
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(base <= 0) return 0;
        if(dp[n][base] != -1) return dp[n][base];
        
        // recursive case
        long long take = f(n-my_pow(base, p), base-1);
        long long notTake = f(n, base-1);
        
        // return case
        long long ans = (take + notTake) % MOD;
        dp[n][base] = ans;
        return ans;
    }
    
    int numberOfWays(int n, int x) {
        p = x;
        std::memset(dp, -1, sizeof dp);
        
        int ans = f(n, n);
        return ans;
    }
};