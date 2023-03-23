// https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm
class Solution {
public:
    // starting from left and going clockwise
    int dx[4] = {0, -1, 0, +1};
    int dy[4] = {-1, 0, +1, 0};
    
    bool isValid(int ni, int nj, vector<vector<int>>& image) {
        return ni>=0 && ni<image.size() && nj>=0 && nj<image[0].size();
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        std::vector<std::vector<int>> vis(image.size(), std::vector<int>(image[0].size(), 0));
        vis[sr][sc] = 1;
        std::queue<std::pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;
        
        while(!q.empty()) {
            sr = q.front().first;
            sc = q.front().second;
            q.pop();
            for(int ind=0; ind<4; ind++) {
                int ni = sr + dx[ind];
                int nj = sc + dy[ind];
                if(isValid(ni, nj, image) && !vis[ni][nj] && image[ni][nj] == oldColor) {
                    vis[ni][nj] = 1;
                    q.push({ni, nj});
                    image[ni][nj] = newColor;
                }
            }
        }
        return image;
    }
};