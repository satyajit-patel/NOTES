//https://practice.geeksforgeeks.org/problems/count-all-possible-paths-from-top-left-to-bottom-right3011/1
#define vi vector<int>
#define vvi vector<vector<int>>
class Solution {
public:
    long long int countPaths(int i, int j, int n, int m, vvi &vis) {
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] == 1) return 0;
        if(i == n-1 && j == m-1) return 1;
        int dx[] = {0,+1};
        int dy[] = {+1,0};
        long long int cnt = 0;
        vis[i][j] = 1;
        for(int ind=0; ind<2; ind++) {
            int newI = i + dx[ind];
            int newJ = j + dy[ind];
            cnt += countPaths(newI, newJ, n, m, vis);
        }
        vis[i][j] = 0;
        return cnt;
    }
    long long int numberOfPaths(int m, int n){
        vvi vis(n, vi(m, 0));
        int ans = countPaths(0,0,n,m,vis);
        return ans;
    }
};