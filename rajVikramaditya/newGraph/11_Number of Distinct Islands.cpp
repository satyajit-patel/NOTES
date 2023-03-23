// https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands
class Solution {
public:
    // starting from left and going clockwise
    int dx[4] = {0, -1, 0, +1};
    int dy[4] = {-1, 0, +1, 0};
    
    bool isValid(int ni, int nj, vector<vector<int>>& image) {
        return ni>=0 && ni<image.size() && nj>=0 && nj<image[0].size();
    }

    void dfs(int i, int j, int base_i, int base_j, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int, int>>& shape) {
        vis[i][j] = 1;
        shape.push_back({i-base_i, j-base_j});
        
        for(int ind=0; ind<4; ind++) {
            int ni = i + dx[ind];
            int nj = j + dy[ind];
            if(isValid(ni, nj, grid) && !vis[ni][nj] && grid[ni][nj]==1) dfs(ni, nj, base_i, base_j, grid, vis, shape);
        }
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        int N = grid.size();
        int M =grid[0].size();
        std::set<std::vector<std::pair<int, int>>> st;
        std::vector<std::vector<int>> vis(N, std::vector<int>(M, 0));
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(!vis[i][j] && grid[i][j]==1) {
                    std::vector<std::pair<int, int>> shape;
                    dfs(i, j, i, j, grid, vis, shape);
                    st.insert(shape);
                }
            }
        }
        return st.size();
    }
};