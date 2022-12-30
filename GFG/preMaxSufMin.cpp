#include<bits/stdc++.h>

using namespace std;
vector<int> preMax(vector<int> arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    for(int i=0; i<n; i++) {
        if(i == 0) { 
        ans[i] = arr[i];
            continue;
        }
        ans[i] = max(arr[i], ans[i-1]);
    }
    return ans;
}
vector<int> sufMIn(vector<int> arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    for(int i=n-1; i>=0; i--) {
        if(i == n-1) {
            ans[i] = arr[i];
            continue;
        }
        ans[i] = min(arr[i], ans[i+1]);
    }
    return ans;
}
int main() {
    vector<int> arr = {5,4,1,10,12};
    int n = arr.size();
    vector<int> pre = preMax(arr);
    vector<int> suf = sufMIn(arr);
    int ans = INT_MAX;
    for(int i=0; i<n; i++) ans = min(ans, pre[i]-suf[i+1]);
    cout<<ans;
    return 0;
}