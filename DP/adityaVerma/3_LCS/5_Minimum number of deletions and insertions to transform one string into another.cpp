// https://leetcode.com/problems/delete-operation-for-two-strings/description/
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

    int minDistance(string& word1, string& word2) {
        int lcs = f(word1, word2);
        // conversion :- word1 --> lcs --> word2
        int deleteOperation = word1.size() - lcs;
        int insertOperation = word2.size() - lcs;
        int totalOperation  = deleteOperation + insertOperation;
        return totalOperation;
    }
};