// https://leetcode.com/problems/number-of-islands/description/
class Solution {
private:
    // left to right clockwise
    int dx[4] = {0, -1, 0, +1};
    int dy[4] = {-1, 0, +1, 0};

    bool isValid(int i, int j, std::vector<std::vector<char>>& grid) {
        return i>=0 && i<grid.size() && j>=0 && j<grid[i].size();
    }

    void bfs(int i, int j, std::vector<std::vector<char>>& grid) {
        std::queue<std::pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            for(int ind=0; ind<4; ind++) {
                int ni = i + dx[ind];
                int nj = j + dy[ind];
                if(isValid(ni, nj, grid) && grid[ni][nj]=='1') {
                    grid[ni][nj] = '0';
                    q.push({ni, nj});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    bfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};