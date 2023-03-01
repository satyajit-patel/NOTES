//https://leetcode.com/problems/maximal-square/submissions/
class Solution {
public:
    int f(int i, int j, vector<vector<char>>& matrix, int& maxi, vector<vector<int>>& dp) {
        //baseCase
        if(i >= matrix.size()) return 0;
        if(j >= matrix[i].size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int right = f(i, j+1, matrix, maxi, dp);
        int corner = f(i+1, j+1, matrix, maxi, dp);
        int down = f(i+1, j, matrix, maxi, dp);
        
        int ans = 0;
        if(matrix[i][j] == '1') ans = 1 + min(right, min(corner, down));
        maxi = max(maxi, ans);
        dp[i][j] = ans;
        return ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix[0].size(), -1));
        f(0, 0, matrix, maxi, dp);
        return maxi*maxi;
    }
};