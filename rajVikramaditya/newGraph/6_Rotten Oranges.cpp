// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges
class Solution {
public:
    // starting from left and going clockwise
    int dx[4] = {0, -1, 0, +1};
    int dy[4] = {-1, 0, +1, 0};
    
    bool isValid(int ni, int nj, vector<vector<int>>& image) {
        return ni>=0 && ni<image.size() && nj>=0 && nj<image[0].size();
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int rot = 0;
        int tot = 0;
        std::queue<std::pair<std::pair<int, int>, int>> q;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) q.push({{i, j}, ans});
            }
        }
        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            q.pop();
            ans = std::max(ans, t);
            rot++;
            for(int ind=0; ind<4; ind++) {
                int ni = i + dx[ind];
                int nj = j + dy[ind];
                if(isValid(ni, nj, grid) && grid[ni][nj] == 1) {
                    grid[ni][nj] = 2;
                    q.push({{ni, nj}, ans+1});
                }
            }
        }
        if(rot == tot) return ans;
        return -1;
    }
};