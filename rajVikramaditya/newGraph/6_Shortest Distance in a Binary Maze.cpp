// https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze
class Solution {
public:
    int dx[4] = {-1, 0, +1, 0}; // starting from top clock wise
    int dy[4] = {0, +1, 0, -1};
    bool isValid(int ni, int nj, vector<vector<int>> &grid) {
        return ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size();
    }

    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        int mini = 1e9;
        int N = grid.size(), M = grid[0].size();
        int si = source.first, sj = source.second;
        int di = destination.first, dj = destination.second;
        std::vector<std::vector<int>> vis(N, std::vector<int>(M, 0));
        vis[si][sj] = 1;
        std::queue<std::pair<std::pair<int, int>, int>> q;
        q.push({{si, sj}, 0});
        
        while(!q.empty()) {
            si = q.front().first.first;
            sj = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            if(si==di && sj == dj) mini =min(mini, steps);
            
            for(int ind=0; ind<4; ind++) {
                int ni = si + dx[ind];
                int nj = sj + dy[ind];
                if(isValid(ni, nj, grid) && !vis[ni][nj] && grid[ni][nj]==1) {
                    vis[ni][nj] = 1;
                    q.push({{ni, nj}, steps+1});
                }
            }
        }
        if(mini == 1e9) return -1;
        return mini;
    }
};