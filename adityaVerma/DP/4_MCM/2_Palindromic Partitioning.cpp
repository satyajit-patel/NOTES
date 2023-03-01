// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    bool isPalindrome(int i, int j, string& s) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int dp[500+1][500+1];
    int f(int i, int j, string& s) {
        // base case
        if(i >= j) return 0;
        if(isPalindrome(i, j, s)) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for(int k=i; k<j; k++) {
            int cost = 1 + f(i, k, s) + f(k+1, j, s);
            mini = std::min(mini, cost);
        }
        dp[i][j] = mini;
        return mini;
    } 

    int palindromicPartition(string& str) {
        std::memset(dp, -1, sizeof dp);
        return f(0, str.size()-1, str);
    }
};