//https://leetcode.com/problems/wildcard-matching/submissions/
class Solution {
public:
    bool isAllStar(int n, string &s) {
        for(int i=n; i>=0; i--) {
            if(s[i] != '*') return false;
        }
        return true;
    }
    bool f(int n , int m, string &s, string &t, vector<vector<int>> &dp) {
        if(n < 0 && m < 0) return true;
	//there still cm remaining but we don't have anything left to compare to
        if(n < 0 && m >= 0) return false;
        if(m < 0 && n >=0) return isAllStar(n, s);
        if(dp[n][m] != -1) return dp[n][m];
        
        bool match = false, notMatch = false;
        if(s[n] == t[m] || s[n] == '?') match = f(n-1, m-1, s, t, dp);
        else {
            if(s[n] == '*') {
                bool starIsNothingLeave = f(n-1, m, s, t, dp);
                bool starIsEverythingStay = f(n, m-1, s, t, dp);
                notMatch = starIsNothingLeave || starIsEverythingStay;
            }
            else notMatch = false;   
        }
        return dp[n][m] = match || notMatch;
    }

    bool isMatch(string &s, string &p) {
        vector<vector<int>> dp(p.size()+1, vector<int>(s.size()+1, -1));
        return f(p.size()-1, s.size()-1, p, s, dp);
    }
};