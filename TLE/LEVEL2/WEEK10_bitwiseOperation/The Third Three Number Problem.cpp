#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
const int MOD = 1e9 + 7;

// ----------------------------------------------------------------------------------------------------

// link:- https://codeforces.com/problemset/problem/1699/A

void input() {
    int tc; cin>>tc;
    while(tc--) {
        int n; cin>>n;
        if(n&1 == 1) cout<<-1<<endl;
        else cout<<0<<" "<<n/2<<" "<<n/2<<endl;
    }
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    input();
    return 0;
}