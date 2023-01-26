// https://leetcode.com/problems/longest-palindromic-subsequence/description/
class Solution {
public:
    int f(string& s1, string& s2, vector<vector<int>>& dp, int i=0, int j=0) {
        // base case
        if(i == s1.size()) return 0;
        if(j == s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(s1[i] == s2[j]) {
            ans += 1 + f(s1, s2, dp, i+1, j+1);
        }
        else {
            int opr1 = f(s1, s2, dp, i+1, j);
            int opr2 = f(s1, s2, dp, i, j+1);
            ans += std::max(opr1, opr2);
        }

        dp[i][j] = ans;
        return ans;
    }
    int longestCommonSubsequence(string& text1, string& text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, -1));
        return f(text1, text2, dp);
    }
    int longestPalindromeSubseq(string s) {
        string temp = s;
        std::reverse(temp.begin(), temp.end());
        return longestCommonSubsequence(temp, s);
    }
};