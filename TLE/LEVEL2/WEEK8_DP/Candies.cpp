#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
// #define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
const int MOD = 1e9 + 7;

// ----------------------------------------------------------------------------------------------------

// link:- https://atcoder.jp/contests/dp/tasks/dp_m

int f(int index, int k, int* val, int n, vvi& dp) {
    // base case
    if(index >= n) return (k == 0);
    if(k == 0) return 1;
    if(k < 0) return 0;
    if(dp[index][k] != -1) return dp[index][k];

    // recursive case
    int sum = 0;
    for(int i=0; i<=val[index]; i++) {
        if(i <= k) sum += f(index+1, k-i, val, n, dp);
        sum %= MOD;
    }
    
    // store and return
    dp[index][k] = sum;
    return sum;
}

void input() {
    int n,k; cin>>n>>k;
    int val[n];
    for(int i=0; i<n; i++) cin>>val[i];
    vvi dp(n+1, vi(k+1, -1));

    // memoization is giving TLE 
    cout<<f(0, k, val, n, dp)<<endl;
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    input();
    return 0;
}