// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
class Solution{
public:
    int f(int i, int j, int* arr, vector<vector<int>>& dp) {
        // base case
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        for(int k=i; k<j; k++) {
            int left    = f(i, k, arr, dp);
            int right   = f(k+1, j, arr, dp);
            int cost    = arr[i-1] * arr[j] * arr[k];
            int total   = left + right + cost;
            ans = std::min(ans, total);
        }
        dp[i][j] = ans;
        return ans;
    }
    int matrixMultiplication(int N, int arr[]) {
        vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
        return f(1, N-1, arr, dp);
    }
};