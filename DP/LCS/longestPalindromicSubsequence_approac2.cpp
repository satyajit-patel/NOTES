// https://leetcode.com/problems/longest-palindromic-subsequence/description/
class Solution {
public:
    int dp[1000+1][1000+1];
    int f(int i, int j, string& s1, string& s2, int N, int M) {
        // base case
        if(i >= N) return 0;
        if(j >= M) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        // recursive case
        int count = 0;
        if(s1[i] == s2[j]) count = 1 + f(i+1, j+1, s1, s2, N, M);
        else count = std::max(f(i+1, j, s1, s2, N, M), f(i, j+1, s1, s2, N, M));

        // store and return
        dp[i][j] = count;
        return count;
    }
    int longestCommonSubsequence(string& s1, string& s2) {
        std::memset(dp, -1, sizeof dp);
        int N = s1.size();
        int M = s2.size();
        return f(0, 0, s1, s2, N, M);
    }
    int longestPalindromeSubseq(string& s) {
        string temp = s;
        std::reverse(temp.begin(), temp.end());
        return longestCommonSubsequence(temp, s);
    }
};