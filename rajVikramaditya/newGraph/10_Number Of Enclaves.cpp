// https://practice.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves
class Solution {
public:
    // starting from left and going clockwise
    int dx[4] = {0, -1, 0, +1};
    int dy[4] = {-1, 0, +1, 0};
    
    bool isValid(int ni, int nj, vector<vector<int>>& image) {
        return ni>=0 && ni<image.size() && nj>=0 && nj<image[0].size();
    }

    int numberOfEnclaves(vector<vector<int>> &grid) {
        int N = grid.size();
        int M = grid[0].size();
        std::vector<std::vector<int>> vis(N, std::vector<int>(M, 0));
        std::queue<std::pair<int, int>> q;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(i==0 && grid[i][j]==1) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
                if(i==N-1 && grid[i][j]==1) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
                if(j==0 && grid[i][j]==1) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
                if(j==M-1 && grid[i][j]==1) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            grid[i][j] = 0;
            for(int ind=0; ind<4; ind++) {
                int ni = i + dx[ind];
                int nj = j + dy[ind];
                if(isValid(ni, nj, grid) && !vis[ni][nj] && grid[ni][nj]==1) {
                    vis[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }
        int land = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) if(grid[i][j] == 1) land++;
        }
        return land;
    }
};