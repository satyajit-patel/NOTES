// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having-1
class Solution {
public:
    // starting from left and going clockwise
    int dx[4] = {0, -1, 0, +1};
    int dy[4] = {-1, 0, +1, 0};
    
    bool isValid(int ni, int nj, vector<vector<int>>& image) {
        return ni>=0 && ni<image.size() && nj>=0 && nj<image[0].size();
    }

	vector<vector<int>>nearest(vector<vector<int>>grid) {
	    std::vector<std::vector<int>> vis(grid.size(), std::vector<int>(grid[0].size(), 0));
	    std::queue<std::pair<std::pair<int, int>, int>> q;
	    for(int i=0; i<grid.size(); i++) {
	        for(int j=0; j<grid[i].size(); j++) {
	            if(grid[i][j] == 1) {
	                vis[i][j] = 1;
	                q.push({{i, j}, 0});
	            }
	        }
	    }
	    while(!q.empty()) {
	        int i = q.front().first.first;
	        int j = q.front().first.second;
	        int d = q.front().second;
	        q.pop();
	        grid[i][j] = d;
	        for(int ind=0; ind<4; ind++) {
	            int ni = i + dx[ind];
	            int nj = j + dy[ind];
	            if(isValid(ni, nj, grid) && !vis[ni][nj] && grid[ni][nj] == 0) {
	                vis[ni][nj] = 1;
	                q.push({{ni, nj}, d+1});
	            }
	        }
	    }
	    return grid;
	}
};