#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"

void sub(int i, int n, vi &arr, vi &ds, vvi &ans) {
    if(i == n) {
        ans.push_back(ds);
        return;
    }
    ds.push_back(arr[i]);
    sub(i+1, n, arr, ds, ans);
    ds.pop_back();
    sub(i+1, n, arr, ds, ans);
}
int main() {
    int n; cin>>n;
    vi arr(n);
    for(auto &it : arr) cin>>it;
    vi ds;
    vvi ans;
    sub(0, n, arr, ds, ans);
    for(auto &row : ans) {
        cout<<"{";
        for(auto &it : row) cout<<it;
        cout<<"}";
    }
    return 0;
}