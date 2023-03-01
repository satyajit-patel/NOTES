// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    int dp[500+1][500+1];
    int f(int i, int j, int* A) {
        // base case
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        // recursive case
        int optimal = 1e9;
        for(int k=i; k<j; k++) {
            int cost  = A[i-1] * A[j] * A[k] + f(i, k, A) + f(k+1, j, A);
            optimal   = std::min(optimal, cost);
        }
        
        // store and return
        dp[i][j] = optimal;
        return optimal;
    }
    int matrixMultiplication(int N, int arr[]) {
        std::memset(dp, -1, sizeof dp);
        return f(1, N-1, arr);
    }
};