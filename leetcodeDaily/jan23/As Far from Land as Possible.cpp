// https://leetcode.com/problems/as-far-from-land-as-possible/description/
#define vi vector<int>
#define vvi vector<vector<int>>
int dx[] = {-1, 0, +1, 0};
int dy[] = {0, +1, 0, -1};
class Solution {
public:
    bool isValid(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vvi allLand(n, vi(m, 1));
        vvi allWater(n, vi(m, 0));
        if(grid == allWater || grid == allLand) return -1;
        
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) q.push({i, j});
            }
        }
        int farthestWaterLevel = -1;
        while(!q.empty()) {
            farthestWaterLevel++;
            int size = q.size();
            for(int x=0; x<size; x++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int ind=0; ind<4; ind++) {
                    int ni = i + dx[ind];
                    int nj = j + dy[ind];
                    if(isValid(ni, nj, n, m) && grid[ni][nj] == 0) {
                        grid[ni][nj] = 1;
                        q.push({ni, nj});
                    }
                }
            }
        }
        return farthestWaterLevel;    
    }
};