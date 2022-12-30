#include<bits/stdc++.h>
using namespace std;


#define log(args...)    { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << endl;
    err(++it, args...);
}




#define     IOS     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define     endl    "\n" 
#define     int     long long int
#define     vi      vector<int>
#define     vvi     vector<vector<int>>
#define     vvc     vector<vector<char>>
#define     vpi     vector<pair<int, int>>

//---------------------------------------------------------------------


// https://cses.fi/problemset/task/1624/
bool isSafe(int row, int col, int n, vvc& board) {
    if(board[row][col] == '*') return false;

    // leftUpCorner
    for(int i=row,j=col; i>=0 && j>=0; i--,j--) {
        if(board[i][j] == 'Q') return false;
    }
    // left
    for(int i=row,j=col; j>=0; j--) {
        if(board[i][j] == 'Q') return false;
    } 
    // leftDownCorner
    for(int i=row,j=col; i<n && j>=0; i++,j--) {
        if(board[i][j] == 'Q') return false;
    }
    
    return true;
}
int f(int j, int n, vvc& board) {
    //base case
    if(j == n) return 1;

    int count = 0;
    for(int i=0; i<n; i++) {
        if(isSafe(i, j, n, board)) {
            board[i][j] = 'Q';
            count += f(j+1, n, board);
            //backtrack
            board[i][j] = '.';
        }
    }
    return count;
}
void input() {
    vvc board;
    for(int i=0; i<8; i++) {
        vector<char> temp;
        for(int j=0; j<8; j++) {
            char c; cin>>c;
            temp.push_back(c);
        }
        board.push_back(temp);
    }
    cout<<f(0, 8, board)<<endl;
}

//------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

