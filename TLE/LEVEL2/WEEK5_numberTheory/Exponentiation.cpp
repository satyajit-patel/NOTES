#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
#define IOS     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

// ----------------------------------------------------------------------------------------------------

// https://cses.fi/problemset/task/1095

int my_pow(int base, int power, int mod) {
    int ans = 1;
    while(power) {
        if(power&1) ans = ((ans % mod) * (base % mod)) % mod;
        base = ((base % mod) * (base%mod)) % mod;
        power >>= 1;
    }
    return ans;
}

void input() {
    int n; cin>>n;
    while(n--) {
        int a, b; cin>>a>>b;
        int mod = (int) 1e9 + 7;
        cout<<my_pow(a%mod, b%mod, mod)<<endl;
    }
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

