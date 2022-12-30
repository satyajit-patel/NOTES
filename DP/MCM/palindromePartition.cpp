// https://leetcode.com/problems/palindrome-partitioning-ii/description/
class Solution {
public:
    bool isPalindrome(int i, int j, string& s) {
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    int f(int i, int n, string& s, vector<int>& dp) {
        // base case
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;
        for(int j=i; j<n; j++) {
            if(isPalindrome(i, j, s)) {
                int cut = 1 + f(j+1, n, s, dp);
                ans = std::min(ans, cut);
            }
        }
        dp[i] = ans;
        return ans;
    } 
    int minCut(string s) {
        vector<int> dp(s.size()+1, -1);
        return f(0, s.size(), s, dp) - 1; // -1 for extra cut at end
    }
};