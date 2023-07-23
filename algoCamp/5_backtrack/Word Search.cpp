// https://leetcode.com/problems/word-search/description/
class Solution {
private: 
    vector<vector<char>> board;
    string word;
    // left up right down
    int dx[4] = {0, -1, 0, +1};
    int dy[4] = {-1, 0, +1, 0};

    bool isValid(int i, int j, vector<vector<char>>& board) {
        return i>=0 && i<board.size() && j>=0 && j<board[i].size();
    }

    bool f(int i, int j, vector<vector<char>>& board, int index) {
        // base case
        if(index >= this->word.size()) return true;
        if(!isValid(i, j, board)) return false;
        if(board[i][j] != this->word[index]) return false;

        // recursive case
        board[i][j] = '#';
        for(int ind=0; ind<4; ind++) {
            int ni = i + dx[ind], nj = j + dy[ind];
            if(f(ni, nj, board, index+1)) return true;
        }
        // backtrack
        board[i][j] = this->board[i][j];

        // return case
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string& word) {
        this->board = board;
        this->word = word;
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) if(f(i, j, board, 0)) return true;
        }
        return false;
    }
};