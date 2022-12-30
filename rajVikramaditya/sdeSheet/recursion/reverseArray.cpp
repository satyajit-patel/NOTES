#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"

//tc->O(N/2), sc->O(N/2)
void rev(int i, int n, vi &arr) {
   if(i >= n/2) return;
   swap(arr[i], arr[n-i-1]);
   rev(i+1, n, arr);
}
int main() {
    int n; cin>>n;
    vi arr(n);
    for(auto &it : arr) cin>>it;
    rev(0, arr.size(), arr);
    for(auto &it : arr) cout<<it<<" ";
    return 0;
}