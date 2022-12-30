//https://leetcode.com/problems/pizza-with-3n-slices/submissions/
class Solution {
public:
    int f(int i, int j, vector<int> &a, int n, vector<vector<int>> &dp) {
        //baseCase
        if(n == 0 || i > j) return 0;
        if(dp[i][n] != -1) return dp[i][n];
        
        //recursiveCase
        int include = a[i] + f(i+2, j, a, n-1, dp);
        int exclude = 0 + f(i+1, j, a, n, dp);
        return dp[i][n] = max(include, exclude);
    }
    int maxSizeSlices(vector<int>& slices) {
        int totalSlice = slices.size();
        int mySlice = totalSlice/3;
        int n = slices.size();
        //num of changing parametre = 2
        vector<vector<int>> dp1(n+1, vector<int>(mySlice+1, -1));
        int option1 = f(0, n-2, slices, mySlice, dp1);
        vector<vector<int>> dp2(n+1, vector<int>(mySlice+1, -1));
        int option2 = f(1, n-1, slices, mySlice, dp2);
        return max(option1, option2);
    }
};