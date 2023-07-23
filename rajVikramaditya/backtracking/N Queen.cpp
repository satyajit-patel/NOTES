#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>

bool isSafe(int row, int col, int N, vii &chessBoard) {
    for(int i=row,j=col; i>=0 && j>=0; i--,j--) if(chessBoard[i][j] == 1) return false; //leftUpDiagonal
    for(int j=col; j>=0; j--) if(chessBoard[row][j] == 1) return false; //left
    for(int i=row,j=col; i<N && j>=0; i++,j--) if(chessBoard[i][j] == 1) return false; //leftDownDiagonal

    return true;
}
bool nQueen(int col, int N, vii &chessBoard, vii &ans) {
    //baseCase
    if(col == N) {
        ans = chessBoard;
        return true;
    }

    //recursiveCase
    for(int i=0; i<N; i++) {
        if(isSafe(i, col, N, chessBoard)) {
            //place&go
            chessBoard[i][col] = 1;
            if(nQueen(col+1, N, chessBoard, ans) == true) return true;
            chessBoard[i][col] = 0; //backtrack
        }
    }
    return false;
}
int main() {
    int n = 4;
    vii chessBoard(n, vector<int>(n, 0));
    vii ans(n, vector<int>(n, 0));
    nQueen(0, n, chessBoard, ans);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}