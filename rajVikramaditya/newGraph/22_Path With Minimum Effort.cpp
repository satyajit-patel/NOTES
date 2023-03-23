// https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=path-with-minimum-effort
class Solution {
public:
    int dx[4] = {+1, 0, -1, 0};
    int dy[4] = {0, +1, 0, -1};
    bool isValid(int ni, int nj, vector<vector<int>> &grid) {
        return ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size();
    }

    int MinimumEffort(vector<vector<int>>& heights) {
        int N = heights.size(), M = heights[0].size();
        std::vector<std::vector<int>> dist(N, std::vector<int>(M, INT_MAX));
        dist[0][0] = 0;
        std::priority_queue<std::pair<int, std::pair<int, int>>> q;
        q.push({dist[0][0] * -1, {0, 0}});
        
        while(!q.empty()) {
            int diff = q.top().first * -1;
            int i = q.top().second.first;
            int j = q.top().second.second;
            q.pop();
            if(i==N-1 && j==M-1) return diff;
            
            for(int ind=0; ind<4; ind++) {
                int ni = i + dx[ind];
                int nj = j + dy[ind];
                if(isValid(ni, nj, heights)) {
                    int maxDiff = std::max(diff, std::abs(heights[ni][nj] - heights[i][j]));
                    if(maxDiff < dist[ni][nj]) {
                        dist[ni][nj] = maxDiff;
                        q.push({dist[ni][nj] * -1, {ni, nj}});
                    }
                }
            }
        }
        return 0;
    }
};