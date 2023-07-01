// https://leetcode.com/problems/flood-fill/description/
class Solution {
private:
    // left to right clockwise
    int dx[4] = {0, -1, 0, +1};
    int dy[4] = {-1, 0, +1, 0};

    bool isValid(int i, int j, std::vector<std::vector<int>>& grid) {
        return i>=0 && i<grid.size() && j>=0 && j<grid[i].size();
    }

    void bfs(int i, int j, std::vector<std::vector<int>>& grid, int oldColor, int newColor) {
        std::queue<std::pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            grid[i][j] = newColor;
            for(int ind=0; ind<4; ind++) {
                int ni = i + dx[ind];
                int nj = j + dy[ind];
                if(isValid(ni, nj, grid) && grid[ni][nj]==oldColor) q.push({ni, nj});
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        bfs(sr, sc, image, image[sr][sc], color);
        return image;
    }
};