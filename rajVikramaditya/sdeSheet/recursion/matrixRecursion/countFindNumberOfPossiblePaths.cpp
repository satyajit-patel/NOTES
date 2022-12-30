#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vector<int>>
#define endl "\n"

int countFindPaths(int i, int j, int n, vvi &mat, vvi &vis) {
    if(i>=n || j>=n || i<0 || j<0 || vis[i][j] == 1 || mat[i][j] == 0) return 0;
    if(i == n-1 && j == n-1) return 1;
    int dx[] = {-1,0,+1,0};
    int dy[] = {0,+1,0,-1};
    vis[i][j] = 1;
    int cnt = 0;
    for(int ind=0; ind<4; ind++) {
        int newI = i + dx[ind];
        int newJ = j + dy[ind];
        cnt += countFindPaths(newI, newJ, n, mat, vis);
    }
    vis[i][j] = 0;
    return cnt;
}
int main() {
    int n; cin>>n;
    vvi mat(n, vi(n, 1));
    vvi vis(n, vi(n, 0));
    cout<<countFindPaths(0, 0, n, mat, vis);
    return 0;
}