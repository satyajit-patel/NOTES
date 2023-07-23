// https://leetcode.com/problems/rotting-oranges/description/
class Solution {
private:
    // left to right clockwise
    int dx[4] = {0, -1, 0, +1};
    int dy[4] = {-1, 0, +1, 0};

    bool isValid(int i, int j, std::vector<std::vector<int>>& grid) {
        return i>=0 && i<grid.size() && j>=0 && j<grid[i].size();
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int rot = 0;
        int tot = 0;
        std::queue<std::pair<std::pair<int, int>, int>> q;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) q.push({{i, j}, 0});
            }
        }
        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            q.pop();
            rot++;
            ans = std::max(ans, t);
            for(int ind=0; ind<4; ind++) {
                int ni = i + dx[ind];
                int nj = j + dy[ind];
                if(isValid(ni, nj, grid) && grid[ni][nj] == 1) {
                    grid[ni][nj] = 2;
                    q.push({{ni, nj}, t+1});
                }
            }
        }
        if(rot == tot) return ans;
        return -1;
    }
};