//link ---> 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vpi vector<pair<int, int>>

int main() {
    int n = 3;
    vii mat(n, vi(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            mat[i][j] = 2 * i;
        }
    }
     for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(auto &it : mat) {
        cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
    }
    cout<<endl;
    for(auto &row : mat) {
        for(auto &it : row) cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}s