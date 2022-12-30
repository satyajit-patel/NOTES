#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"

bool sub(int i, int n, int sum, int k, vi &arr, vi &ds, vi &ans) {
    if(i == n) {
        if(ds.size() != 0 && sum%k == 0) {
            ans = ds;
            return true;
        }
        return false;
    }
    ds.push_back(arr[i]);
    sum += arr[i];
    if(sub(i+1, n, sum, k, arr, ds, ans) == true) return true;
    ds.pop_back();
    sum -= arr[i];
    if(sub(i+1, n, sum, k, arr, ds, ans) == true) return true;
}
int main() {
    int n; cin>>n;
    vi arr(n);
    for(auto &it : arr) cin>>it;
    vi ds;
    vi ans;
    sub(0, n, 0, 3, arr, ds, ans);
    for(auto &it : ans) cout<<it;
    return 0;
}