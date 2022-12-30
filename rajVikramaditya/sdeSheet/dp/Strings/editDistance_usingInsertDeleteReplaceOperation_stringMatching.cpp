//https://leetcode.com/problems/edit-distance/submissions/
class Solution {
public:
    int f(int n, int m, string &s, string &t, vector<vector<int>> &dp) {
        if(m < 0) return n-0+1;
        if(n < 0) return m-0+1;
        if(dp[n][m] != -1) return dp[n][m];
        
        int match = 0, notMatch = 0;
        if(s[n] == t[m]) match = 0 + f(n-1, m-1, s, t, dp);
        else {
            int insertOp = 1 + f(n, m-1, s, t, dp);
            int deleteOp = 1 + f(n-1, m, s, t, dp);
            int replaceOp = 1 + f(n-1, m-1, s, t, dp);
            notMatch = min(insertOp, min(deleteOp, replaceOp));
        }
        return dp[n][m] = match + notMatch;
    }
    int minDistance(string &word1, string &word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(n-1, m-1, word1, word2, dp);
    }
};