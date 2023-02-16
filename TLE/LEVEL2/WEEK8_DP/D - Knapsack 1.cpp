#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>

// ----------------------------------------------------------------------------------------------------

// link:- https://atcoder.jp/contests/dp/tasks/dp_d

int f(int W, vi& wt, vi& val, vvi& dp, int i=0) {
    // base case 
    if(i >= val.size()) return 0;
    if(W <= 0) return 0;
    if(dp[i][W] != -1) return dp[i][W];

    // choice
    int include = 0, exclude = 0;
    if(wt[i] <= W) include = val[i] + f(W - wt[i], wt, val, dp, i+1);
    exclude = 0 + f(W, wt, val, dp, i+1);

    int optimal = std::max(include, exclude);
    dp[i][W] = optimal;
    return optimal;
}

void input() {
    int N,W; cin>>N>>W;
    vi wt, val;
    for(int i=0; i<N; i++) {
        int weight, value; cin>>weight>>value;
        wt.push_back(weight);
        val.push_back(value);
    }
    vvi dp(100+1, vi(100000+1, -1));
    cout<<f(W, wt, val, dp)<<endl;
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    input();
    return 0;
}

