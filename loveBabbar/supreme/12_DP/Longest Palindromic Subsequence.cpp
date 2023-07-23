// https://leetcode.com/problems/longest-palindromic-subsequence/description/
class Solution {
private:
    string s1, s2;
    vector<vector<int>> dp;

    int f(int i, int j) {
        // base case
        if(i >= s1.size()) return 0;
        if(j >= s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        // recursive case
        int maxi = INT_MIN;
        if(s1[i] == s2[j]) {
            int ans = f(i+1, j+1);
            maxi = std::max(maxi, 1+ans);
        }
        else {
            int case1Ans = f(i+1, j);
            int case2Ans = f(i, j+1);
            maxi = std::max(case1Ans, case2Ans);
        }

        // return case
        dp[i][j] = maxi;
        return maxi;
    }

    int longestCommonSubsequence(string text1, string text2) {
        s1 = text1, s2 = text2;
        dp.resize(s1.size()+1, vector<int>(s2.size()+1, -1));
        return f(0, 0);
    }
public:
    int longestPalindromeSubseq(string s) {
        string temp = s;
        std::reverse(s.begin(), s.end());
        return longestCommonSubsequence(temp, s);
    }
};