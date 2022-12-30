#define vi vector<int>
#define vs vector<string>
#define vvi vector<vector<int>>
//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
class Solution{
public:
    void findPaths(int i, int j, int n, vvi &mat, string s, vvi &vis, vs &ans) {
        if(i>=n || j>=n || i<0 || j<0 || vis[i][j] == 1 || mat[i][j] == 0) return;
        if(i == n-1 && j == n-1) {
            ans.push_back(s);
            return;
        }
        int dx[] = {-1,0,+1,0};
        int dy[] = {0,+1,0,-1};
        string dir = "URDL";
        vis[i][j] = 1;
        for(int ind=0; ind<4; ind++) {
            int newI = i + dx[ind];
            int newJ = j + dy[ind];
            s += dir[ind];
            findPaths(newI, newJ, n, mat, s, vis, ans);
            s.pop_back();
        }
        vis[i][j] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vvi vis(n, vi(n, 0));
        vs ans;
        findPaths(0, 0, n, m, "", vis, ans);
        return ans;
    }
};