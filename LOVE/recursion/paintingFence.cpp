/*
Given a fence with n posts and k colors, 
find out the number of ways of painting the fence 
so that not more than two consecutive fences have the same colors. 
Since the answer can be large return it modulo 10^9 + 7.


Example 1:

Input:
N=3,  K=2 
Output: 6



*/

class Solution{
    public:
    int M = (int)(1e9+7);
    long long f(int n, int k, vector<long long> &dp) {
        //baseCase
        if(n == 1) return k;
        if(n == 2) return k*k;
        if(dp[n] != -1) return dp[n];
        
        //recursiveCase
        long long same = f(n-2, k, dp) * (k-1);
        long long diff = f(n-1, k, dp) * (k-1);
        return dp[n] = (same + diff) % M;
    }
    long long countWays(int n, int k){
        //num of changing parametre = 1 ...so 1D dp
        vector<long long> dp(n+1, -1);
        return f(n, k, dp);
    }
};