#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"

bool isSafe(int row, int col, vvi &mat) {
    for(int j=col; j>=0; j--) if(mat[row][j] == 1) return false;
    for(int i=row,j=col; i>=0 && j>=0; i--,j--) if(mat[i][j] == 1) return false;
    for(int i=row,j=col; i<mat.size() && j>=0; i++,j--) if(mat[i][j] == 1) return false;
    return true;
}
bool nQueen(int j, int n, vvi &mat) {
    if(j == n) return true;
    for(int i=0; i<4; i++) {
        if(isSafe(i, j, mat)) {
            mat[i][j] = 1;
            if(nQueen(j+1, n, mat) == true) return true;
            mat[i][j] = 0;
        }
    }
    return false;
}
int main() {
    int n; cin>>n;
    vvi mat(n, vi(n, 0));
    bool possible = nQueen(0, n, mat);
    if(possible) {
        for(auto &row : mat) {
            for(auto &it : row) cout<<it<<" ";
            cout<<endl;
        }
    }
    else cout<<"not possible";
    return 0;
}