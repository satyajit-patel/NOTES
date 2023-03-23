#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
const int MOD = 1e9 + 7;

// ----------------------------------------------------------------------------------------------------

// link:- https://cses.fi/problemset/task/1093

int f(int i, int sum, int n, vvi& dp) {
    // base case
    if(sum < 0) return 0;
    if(i >= n+1) return 0;
    if(sum == 0) return 1;
    if(dp[i][sum] != -1) return dp[i][sum];

    // recursive case
    int incl = f(i+1, sum-i, n, dp);
    int excl = f(i+1, sum, n, dp);
    int ans = incl + excl;
    ans %= MOD;

    // store and return
    dp[i][sum] = ans;
    return ans;
}

void input() {
    int n; cin>>n;
    int sum = n*(n+1)/2;
    vvi dp(n+1, vi((sum/2)+1, -1));
    if(sum%2 == 1) cout<<0<<endl;
    else cout<<f(1, sum/2, n, dp)<<endl;
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    input();
    return 0;
}