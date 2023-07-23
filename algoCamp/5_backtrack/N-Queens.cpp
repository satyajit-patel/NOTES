// https://leetcode.com/problems/n-queens/description/
class Solution {
private:
     bool isSafe(int row, int col, int n, vector<string>& chessBoard) {
        //leftUp
        for(int i=row,j=col; i>=0 && j>=0; i--,j--) if(chessBoard[i][j] == 'Q') return false;

        //left
        for(int i=row,j=col; i>=0 && j>=0; i,j--) if(chessBoard[i][j] == 'Q') return false;

        //leftDown
        for(int i=row,j=col; i<n && j>=0; i++,j--) if(chessBoard[i][j] == 'Q') return false;

        return true;
    }

    void f(int j, int n, vector<string>& chessBoard, vector<vector<string>>& ans) {
        // base case
        if(j >= n) {
            ans.push_back(chessBoard);
            return;
        }

        // recursive case
        for(int i=0; i<n; i++) {
            if(isSafe(i, j, n, chessBoard)) {
                chessBoard[i][j] = 'Q';
                f(j+1, n, chessBoard, ans);
                // backtrack
                chessBoard[i][j] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> chessBoard(n, string(n, '.'));
        f(0, n, chessBoard, ans);
        return ans;
    }
};