#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
const int MOD = 1e9 + 7;

// ----------------------------------------------------------------------------------------------------

// link:- https://cses.fi/problemset/task/1634

int dp[1000000+1];
int f(vi& coins, int x) {
    // base case
    if(x == 0) return 0;
    if(x < 0) return 1e9;
    if(dp[x] != -1) return dp[x];

    // recursive case
    int mini = 1e9;
    for(auto &it : coins) mini = std::min(mini, 1 + f(coins, x - it));

    // store and return
    dp[x] = mini;
    return mini;
}

void input() {
    int n,x; cin>>n>>x;
    vi coins(n);
    for(auto &it : coins) cin>>it;
    std::memset(dp, -1, sizeof dp);
    int ans = f(coins, x);
    if(ans >= 1e9) cout<<-1<<endl;
    else cout<<ans<<endl;
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    input();
    return 0;
}

