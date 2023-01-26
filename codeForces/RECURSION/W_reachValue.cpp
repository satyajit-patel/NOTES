#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
#define IOS     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

// ----------------------------------------------------------------------------------------------------

// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/W

bool f(int n, int i=1) {
    // base case
    if(i == n) return true;
    if(i > n) return false;

    bool mul_10 = f(n, i*10);
    bool mul_20 = f(n, i*20);

    bool ans = mul_10 || mul_20;
    return ans;
}
void input() {
    int tc; cin>>tc;
    while(tc--) {
        int n; cin>>n;
        if(f(n)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

