//https://leetcode.com/problems/guess-number-higher-or-lower-ii/submissions/
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& dp) {
        //base case
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        for(int dollar=i; dollar<=j; dollar++) {
            mini = min(mini, dollar + max(f(i, dollar-1, dp), f(dollar+1, j, dp)));
        }
        dp[i][j] = mini;
        return mini;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(1, n, dp);
    }
};