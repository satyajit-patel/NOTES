// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands
class Solution {
public:
    // starting from left and going clockwise
    int dx[8] = {0, -1, -1, -1, 0, +1, +1, +1};
    int dy[8] = {-1, -1, 0, +1, +1, +1, 0, -1};
    
    bool isValid(int ni, int nj, vector<vector<char>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        return (ni>=0 && ni<N && nj>=0 && nj<M);
    }

    void bfs(int i, int j, vector<vector<char>>& grid, std::vector<std::vector<int>>& vis) {
        vis[i][j] = 1;
        std::queue<std::pair<int, int>> q;
        q.push({i, j});
        
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int ind=0; ind<8; ind++) {
                int ni = i + dx[ind];
                int nj = j + dy[ind];
                if(isValid(ni, nj, grid) && !vis[ni][nj] && grid[ni][nj]=='1') {
                    vis[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }
    }
        
    int numIslands(vector<vector<char>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        int CC = 0;
        std::vector<std::vector<int>> vis(N, std::vector<int>(M, 0));
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    CC++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return CC;
    }
};