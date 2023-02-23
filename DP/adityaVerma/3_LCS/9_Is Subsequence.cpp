// https://leetcode.com/problems/is-subsequence/description/
class Solution {
public:
    bool isSubsequence(string& s, string& t) {
        int N = s.size(); 
        int M = t.size();
        int dp[N+1][M+1];

        // base case
        for(int i=0; i<=N; i++) dp[i][0] = 0;
        for(int j=0; j<=M; j++) dp[0][j] = 0;

        // tabulation 
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[N][M] == s.size();

        // // print
        // string lcs = "";
        // while(N>0 && M>0) {
        //     if(s[N-1] == t[M-1]) {
        //         lcs += s[N-1];
        //         N--;
        //         M--;
        //     }
        //     else {
        //         if(dp[N][M-1] > dp[N-1][M]) M--;
        //         else N--;
        //     }
        // }
        // std::reverse(lcs.begin(), lcs.end());
        // return lcs == s;
    }
};