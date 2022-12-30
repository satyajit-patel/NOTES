#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"

void sub(int i, int n, int sum, int k, vi &arr, vi &ds, vvi &ans) {
    if(i == n) {
        if(ds.size() != 0 && sum%k == 0) ans.push_back(ds);
        return;
    }
    ds.push_back(arr[i]);
    sum += arr[i];
    sub(i+1, n, sum, k, arr, ds, ans);
    ds.pop_back();
    sum -= arr[i];
    sub(i+1, n, sum, k, arr, ds, ans);
}
int main() {
    int n; cin>>n;
    vi arr(n);
    for(auto &it : arr) cin>>it;
    vi ds;
    vvi ans;
    sub(0, n, 0, 2, arr, ds, ans);
    for(auto &row : ans) {
        cout<<"{";
        for(auto &it : row) cout<<it;
        cout<<"}";
    }
    return 0;
}