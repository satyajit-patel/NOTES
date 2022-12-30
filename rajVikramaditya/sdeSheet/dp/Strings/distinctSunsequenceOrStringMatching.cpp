//https://leetcode.com/problems/distinct-subsequences/
class Solution {
public:
    int f(int n, int m, string &s, string &t, vector<vector<int>> &dp) {
        if(m < 0) return 1;
        if(n < 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        
        int match = 0, notMatch = 0;
        if(s[n] == t[m]) {
            match += f(n-1, m-1, s, t, dp);
            match += f(n-1, m, s, t, dp);
        }
        else notMatch += f(n-1, m, s, t, dp);
        
        return dp[n][m] = match + notMatch;
    }
    int numDistinct(string &s, string &t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(n-1, m-1, s, t, dp);
    }
};