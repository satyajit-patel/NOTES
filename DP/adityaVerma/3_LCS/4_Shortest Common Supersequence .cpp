// https://leetcode.com/problems/shortest-common-supersequence/description/
class Solution {
public:
    string shortestCommonSupersequence(string& str1, string& str2) {
        int N = str1.size();
        int M = str2.size();
        int dp[N+1][M+1];

        // base case
        for(int i=0; i<=N; i++) dp[i][0] = 0;
        for(int j=0; j<=M; j++) dp[0][j] = 0;

        // tabulation
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
            }
        }

        // print
        string lcs = "";
        while(N>0 && M>0) {
            if(str1[N-1] == str2[M-1]) {
                lcs += str1[N-1];
                N--;
                M--;
            }
            else {
                if(dp[N][M-1] > dp[N-1][M]) {
                    lcs += str2[M-1];
                    M--;
                }
                else {
                    lcs += str1[N-1];
                    N--;
                }
            }
        }
        while(N > 0) {
            lcs += str1[N-1];
            N--;
        }
        while(M > 0) {
            lcs += str2[M-1];
            M--;
        }
        std::reverse(lcs.begin(), lcs.end());
        return lcs;
    }
};