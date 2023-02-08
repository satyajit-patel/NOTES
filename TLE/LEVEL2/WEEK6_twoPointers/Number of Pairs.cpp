#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>

// ----------------------------------------------------------------------------------------------------

// link:- https://codeforces.com/problemset/problem/1538/C

void input() {
    int tc; cin>>tc;
    while(tc--) {
        int n,l,r; cin>>n>>l>>r;
        vi arr(n);
        for(auto &it : arr) cin>>it;
        int ans = 0;
        std::sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++) {
            int left  = l - arr[i];
            int right = r - arr[i];
            int idx1  = std::lower_bound(arr.begin() + i+1, arr.end(), left) - arr.begin();
            int idx2  = std::upper_bound(arr.begin() + i+1, arr.end(), right) - arr.begin();
            // we need the numbers between both Ai and Aj
            if(idx1 <= idx2) ans += idx2 - idx1;
        }
        cout<<ans<<endl;
    }
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    input();
    return 0;
}

