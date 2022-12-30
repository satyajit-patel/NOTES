#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"

int subCount(int i, int n, int sum, vi &arr) {
    if(i == n) {
        if(sum == 0) return 1;
        else return 0;
    }
    int left = 0, right = 0;
    if(arr[i] <= sum) {
        sum -= arr[i];
        left = subCount(i, n, sum, arr);
        sum += arr[i];
    }
    right = subCount(i+1, n, sum, arr);
    return left + right;
}
int main() {
    int n; cin>>n;
    vi arr(n);
    for(auto &it : arr) cin>>it;
    cout<<subCount(0, n, 4, arr);
    return 0;
}