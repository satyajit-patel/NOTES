// https://leetcode.com/problems/longest-common-subsequence/submissions/
class Solution {
public:
    int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        // base case
        if(i == s1.size() || j == s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return dp[i][j] = 1 + f(i+1, j+1, s1, s2, dp);
        else {
            int opr1 = f(i+1, j, s1, s2, dp);
            int opr2 = f(i, j+1, s1, s2, dp);
            return dp[i][j] = std::max(opr1, opr2);
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, -1));
        return f(0, 0, text1, text2, dp);
    }
};