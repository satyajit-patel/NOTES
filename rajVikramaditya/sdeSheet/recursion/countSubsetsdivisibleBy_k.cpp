#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"

int sub(int i, int n, int sum, int k, vi &arr) {
    if(i == n) {
        if(sum != 0 && sum%k == 0) return 1;
        else return 0;
    }
    sum += arr[i];
    int left = sub(i+1, n, sum, k, arr);
    sum -= arr[i];
    int right = sub(i+1, n, sum, k, arr);
    return left + right;
}
int main() {
    int n; cin>>n;
    vi arr(n);
    for(auto &it : arr) cin>>it;
    cout<<sub(0, n, 0, 2, arr);
    return 0;
}