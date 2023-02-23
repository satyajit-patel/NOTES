
// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


// lcs sign : 2 strings are given and asking for optimal value

class Solution {
public:
    int dp[1000+1][1000+1];
    int f(int i, int j, string& s1, string& s2, int N, int M) {
        // base case
        if(i >= N) return 0;
        if(j >= M) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        // recursive case
        int optimal = 0;
        if(s1[i] == s2[j]) optimal = 1 + f(i+1, j+1, s1, s2, N, M);
        else optimal = std::max(f(i, j+1, s1, s2, N, M), f(i+1, j, s1, s2, N, M));
        
        // store and return
        dp[i][j] = optimal;
        return optimal;
    }
    
    int lcs(int x, int y, string s1, string s2) {
        int N = s1.size();
        int M = s2.size();
        std::memset(dp, -1, sizeof dp);
        return f(0, 0, s1, s2, N, M);
    }
};