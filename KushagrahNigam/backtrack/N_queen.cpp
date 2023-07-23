#include<bits/stdc++.h>

using namespace std;
void print(vector<vector<char>> &grid, int n)
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    } 
    cout<<"\n";
}
bool safe(int row, int col, int n, vector<vector<char>> &grid)
{
    //leftUP
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(grid[i][j] == 'Q') return false;
    }


    //left
    for(int j=col; j>=0; j--){
        if(grid[row][j] == 'Q') return false;
    }

    //leftDown
    for(int i=row, j=col; i<n && j>=0; i++, j--){
        if(grid[i][j] == 'Q') return false;
    }

    return true;
}
void nqueen(vector<vector<char>> &grid, int n, int col)
{
    //baseCase
    if(col == n){
        print(grid, n);
        return;
    }

    //recursiveCase
    for(int i=0; i<n; i++){  //4 rows for each perticular problem       .   false..........so i++
        if(safe(i, col, n, grid))                                     
        {                                                             //*   false..........so i++
            grid[i][col] = 'Q';                                     
            nqueen(grid, n, col+1); //go                              //.   true...........get inside and replace

            grid[i][col] = '.'; //backTrack                           //.
        }
    }
}
int main()
{
    int n = 4;
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    nqueen(grid, n, 0);
    return 0;
}