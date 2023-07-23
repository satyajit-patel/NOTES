// https://leetcode.com/problems/path-with-minimum-effort/description/
class Solution {
private:
    // left to right clockwise
    int dx[4] = {0, -1, 0, +1};
    int dy[4] = {-1, 0, +1, 0};

    bool isValid(int i, int j, std::vector<std::vector<int>>& grid) {
        return i>=0 && i<grid.size() && j>=0 && j<grid[i].size();
    }

    int dijkstraUsingBfs(vector<vector<int>>& heights) {
        int N = heights.size();
        int M = heights[0].size();
        std::vector<std::vector<int>> dist(N, std::vector<int>(M, INT_MAX));
        std::queue<std::pair<std::pair<int, int>, int>> q;
        dist[0][0] = 0;
        q.push({{0, 0}, dist[0][0]});
        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int curDiff = q.front().second;
            q.pop();
            for(int ind=0; ind<4; ind++) {
                int ni = i + dx[ind];
                int nj = j + dy[ind];
                if(isValid(ni, nj, heights)) {
                    int newDiff = std::abs(heights[ni][nj] - heights[i][j]);
                    int maxi = std::max(newDiff, curDiff);
                    if(maxi < dist[ni][nj]) {
                        dist[ni][nj] = maxi;
                        q.push({{ni, nj}, dist[ni][nj]});
                    }
                }
            }
        }
        return dist[N-1][M-1];
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        return dijkstraUsingBfs(heights);
    }
};