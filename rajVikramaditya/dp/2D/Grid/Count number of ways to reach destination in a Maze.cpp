// https://practice.geeksforgeeks.org/problems/special-matrix4201/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    int MOD = 1e9 + 7;
    int f(vector<vector<int>>& blockPath, int N, int M, vector<vector<int>>& dp, int i=1, int j=1) {
        // base case
        if(i > N) return 0;
        if(j > M) return 0;
        for(auto &row : blockPath) {
            int ni = row[0];
            int nj = row[1];
            if(i==ni && j==nj) return 0;
        }
        if(i == N && j == M) return 1;
        if(dp[i][j] != -1) return dp[i][j];
    
        // recursive case
        int sum = 0;
        sum += f(blockPath, N, M, dp, i, j+1); // right
        sum += f(blockPath, N, M, dp, i+1, j); // down
        sum %= MOD;
    
        // store and return
        dp[i][j] = sum;
        sum;
    }

	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
	    return f(blocked_cells, n, m, dp);
	}
};