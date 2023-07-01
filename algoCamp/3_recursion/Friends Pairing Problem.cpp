// https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    int MOD = 1e9+7;
    long long f(long long N, vector<long long>& dp) {
        // base case
        if(N == 1) return N;
        if(N == 2) return N;
        if(dp[N] != -1) return dp[N];
        
        // recursive case
        long long prev = f(N-1, dp);
        long long prevPrev = f(N-2, dp) * (N-1);
        
        // work case
        long long ans = (prev + prevPrev) % MOD;
        
        // return case
        dp[N] = ans;
        return ans;
    }

    int countFriendsPairings(int n) {
        std::vector<long long> dp(n+1, -1);
        return f(n, dp); 
    }
};    