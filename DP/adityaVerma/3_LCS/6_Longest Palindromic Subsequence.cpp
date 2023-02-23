// https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    int f(string& s1, string& s2) {
        int N = s1.size();
        int M = s2.size();
        int dp[N+1][M+1];
        
        // base case
        for(int i=0; i<=N; i++) dp[i][0] = 0;
        for(int j=0; j<=M; j++) dp[0][j] = 0;
        
        // tabulation
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[N][M];
    }
    int longestPalinSubseq(string& A) {
        string s1 = A;
        std::reverse(A.begin(), A.end());
        string s2 = A;
        return f(s1, s2);
    }
};