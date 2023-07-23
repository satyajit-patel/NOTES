// link => https://atcoder.jp/contests/dp/tasks/dp_d
#include<bits/stdc++.h>
using namespace std;
#define int long long
// -------------------------------------------------------------------------------------------

// global variable
vector<int> wt, val;
vector<vector<int>> dp;

int f(int n, int w) {
    // base case
    if(n < 0) return 0;
    if(w <= 0) return 0;
    if(dp[n][w] != -1) return dp[n][w];
    
    // recursive case
    int incl = INT_MIN;
    if(wt[n] <= w) incl = val[n] + f(n-1, w-wt[n]);
    int excl = f(n-1, w);
    
    // work case
    int ans = max(incl, excl);
    
    // return case
    dp[n][w] = ans;
    return ans;
}

void input() {
    int n, w; cin>>n>>w;
    wt.resize(n), val.resize(n);
    for(int i=0; i<n; i++) cin>>wt[i]>>val[i];
    dp.resize(n, vector<int>(w+1, -1));
    cout<<f(n-1, w)<<"\n";
}

// -------------------------------------------------------------------------------------------
signed main() {
	input();
	return 0;
}
