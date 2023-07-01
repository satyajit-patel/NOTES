// https://practice.geeksforgeeks.org/problems/ways-to-tile-a-floor5836/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
  public:
  int MOD = 1e9 + 7;
    long long f(long long n, vector<long long>& dp) {
        // base case
        if(n <= 2) return n;
        if(dp[n] != -1) return dp[n];

        // recursive case
        long long prev = f(n-1, dp);
        long long prevPrev = f(n-2, dp);

        // work case
        long long ans = (prev + prevPrev) % MOD;

        // return case
        dp[n] = ans;
        return ans;
    }

    long long numberOfWays(long long N) {
        std::vector<long long> dp(N+1, -1);
        return f(N, dp);
    }
};