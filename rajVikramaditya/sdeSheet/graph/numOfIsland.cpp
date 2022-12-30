//link --> https://leetcode.com/problems/number-of-islands/
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
class Solution {
private:
    void bfs(int i, int j, vvi &vis, vvc &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // int dx[] = {-1, -1, 0, +1, +1, +1, 0, -1};
            // int dy[] = {0, +1, +1, +1, 0, -1, 0, -1};
             int dx[] = {-1, 0, +1, 0};
             int dy[] = {0, +1, 0, -1};
            for(int ind=0; ind<4; ind++) {
                int newRow = row + dx[ind];
                int newCol = col + dy[ind];
                if(newRow >= 0 && newRow < n && newCol >=0 && newCol < m 
                && !vis[newRow][newCol] && grid[newRow][newCol] == '1') {
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vvi vis(n, vi(m, 0));
        int island = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    island++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return island;
    }
};