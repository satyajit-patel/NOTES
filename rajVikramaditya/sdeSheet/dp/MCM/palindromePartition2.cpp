//https://leetcode.com/problems/palindrome-partitioning-ii/
class Solution {
public:
    bool isPalindrome(int i, int j, string &s) {
        while(i <= j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    int f(int i, int n, string &s, vector<int> &dp) {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        
        int minCut = INT_MAX;
        for(int j=i; j<n; j++) {
            if(isPalindrome(i, j, s)) {
                int cut = 1 + f(j+1, n, s, dp);
                minCut = min(minCut, cut);
            }
        }
        return dp[i] = minCut;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return f(0, n, s, dp) - 1; //-1 for extra partition at end
    }
};