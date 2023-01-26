// https://leetcode.com/problems/matrix-block-sum/
class Solution {
public:
    vector<vector<int>> f(int n, int m, vector<vector<int>>& mat) {
        vector<vector<int>> A(n+1, vector<int>(m+1));
        vector<vector<int>> P(n+1, vector<int>(m+1));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) A[i][j] = mat[i-1][j-1];
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) P[i][j] = P[i-1][j] + P[i][j-1] + A[i][j] - P[i-1][j-1];
        }
        return P;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(); 
        int m = mat[0].size();
        vector<vector<int>> P = f(n, m, mat);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                int x1 = std::max(1, i-k);
                int y1 = std::max(1, j-k);
                int x2 = std::min(n, i+k);
                int y2 = std::min(m, j+k);
                mat[i-1][j-1] = P[x2][y2] - P[x1-1][y2] - P[x2][y1-1] + P[x1-1][y1-1];  
            }
        }
        return mat;
    }
};