// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
class Solution{
public:
    int dx[4] = {-1,0,+1,0};
    int dy[4] = {0,+1,0,-1};
    string dir = "URDL";
    bool valid(int i, int j, vector<vector<int>>& mat) {
        return i<mat.size() && j<mat.size() && i>=0 && j>=0 && mat[i][j]==1;
    }
    
    void findPaths(vector<vector<int>>& mat, vector<vector<int>>& vis, string& temp, vector<string>& ans, int i=0, int j=0) {
        if(!valid(i, j, mat) || vis[i][j]==1) return;
        if(i == mat.size()-1 && j == mat.size()-1) {
            ans.push_back(temp);
            return;
        }
        vis[i][j] = 1;
        for(int ind=0; ind<4; ind++) {
            int ni = i + dx[ind];
            int nj = j + dy[ind];
            temp.push_back(dir[ind]);
            findPaths(mat, vis, temp, ans, ni, nj);
            temp.pop_back();
        }
        vis[i][j] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        std::vector<std::vector<int>> vis(n, std::vector<int>(n, 0));
        std::vector<std::string> ans;
        std::string temp = "";
        findPaths(m, vis, temp, ans);
        return ans;
    }
};