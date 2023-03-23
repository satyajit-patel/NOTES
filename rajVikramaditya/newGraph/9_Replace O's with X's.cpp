// https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-os-with-xs
class Solution {
public:
    // starting from left and going clockwise
    int dx[4] = {0, -1, 0, +1};
    int dy[4] = {-1, 0, +1, 0};
    
    bool isValid(int ni, int nj, vector<vector<char>>& image) {
        return ni>=0 && ni<image.size() && nj>=0 && nj<image[0].size();
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>>& mat) {
        std::vector<std::vector<char>> ans(n, std::vector<char>(m, 'X'));
        std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
        std::queue<std::pair<int, int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0 && mat[i][j]=='O') {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
                if(i==n-1 && mat[i][j]=='O') {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
                if(j==0 && mat[i][j]=='O') {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
                if(j==m-1 && mat[i][j]=='O') {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            ans[i][j] = 'O';
            for(int ind=0; ind<4; ind++) {
                int ni = i + dx[ind];
                int nj = j + dy[ind];
                if(isValid(ni, nj, mat) && !vis[ni][nj] && mat[ni][nj]=='O') {
                    vis[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }
        return ans;
    }
};