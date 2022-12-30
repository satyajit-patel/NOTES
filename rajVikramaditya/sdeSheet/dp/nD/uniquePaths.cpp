//https://leetcode.com/problems/unique-paths/submissions/
class Solution {
public:
    int dx[2] = {0, -1};
    int dy[2] = {-1, 0};
    int f(int n, int m,vector<vector<int>> &dp) {
        if(n == 0 && m == 0) return 1;
        if(n < 0 || m < 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        
        int count = 0;
        for(int ind=0; ind<2; ind++) {
            int ni = n + dx[ind];
            int nj = m + dy[ind];
            count += f(ni, nj, dp);
        }
        return dp[n][m] = count;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return f(m-1, n-1, dp);
    }
};