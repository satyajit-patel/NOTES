// https://leetcode.com/problems/longest-common-subsequence/description/
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
public:
    int longestCommonSubsequence(string text1, string text2) {
        s1 = text1, s2 = text2;
        dp.resize(s1.size()+1, vector<int>(s2.size()+1, -1));
        return f(0, 0);
    }
};

/*	
			*
			*
			*
			*
*/


// https://practice.geeksforgeeks.org/batch/must-do-1/track/md-dp/problem/longest-common-subsequence-1587115620
class Solution {
public:
    int dp[1005][1005];
    int f(int n, int m, string& s1, string& s2) {
        // base case
        if(n < 0 || m < 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        
        // recursive case
        int ans = 0;
        if(s1[n] == s2[m]) ans = 1 + f(n-1, m-1, s1, s2);
        else ans = std::max(f(n-1, m, s1, s2), f(n, m-1, s1, s2));
        
        // return case
        dp[n][m] = ans;
        return ans;
    }

    int lcs(int n, int m, string& s1, string& s2) {
        std::memset(dp, -1, sizeof dp);
        int ans = f(n-1, m-1, s1, s2);
        return ans;
    }
};
