#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"

void findPath(int i, int j, int n, int m, string s) {
    if(i == n-1 && j == m-1) {
        cout<<s<<endl;
        return;
    }
    if(i >= n || j >= m) return;
    s += 'D';
    findPath(i+1, j, n, m, s);
    s.pop_back();
    s += 'R';
    findPath(i, j+1, n, m, s);
    s.pop_back();
}
int main() {
    int n,m; cin>>n>>m;
    vvi mat(n, vi(m));
    findPath(0, 0, n, m, "");
    return 0;
}