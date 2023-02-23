// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    int longestCommonSubstr (string& S1, string& S2, int n, int m) {
        // base case
        int dp[1000+1][1000+1];
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int j=0; j<=m; j++) dp[0][j] = 0;
        
        // tabulation
        int maxi = 0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(S1[i-1] == S2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0;
                maxi = std::max(maxi, dp[i][j]);
            }
        }
        return maxi;
    }
};