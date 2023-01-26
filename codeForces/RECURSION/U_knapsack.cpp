#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define vi      vector<int>
#define vvi     vector<vector<int>>
#define IOS     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

// ----------------------------------------------------------------------------------------------------

// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U

int f(vi& wt, vi &val, vvi& dp, int knapsack, int i=0) {
    // base case
	if(i == wt.size()) return 0;
	if(dp[i][knapsack] != -1) return dp[i][knapsack];
	
    // include 
	int incl = -1e9;
	if(wt[i] <= knapsack) incl = val[i] + f(wt, val, dp, knapsack-wt[i], i+1);

    // exclude
    int excl = f(wt, val, dp, knapsack, i+1);

    int ans = std::max(incl, excl);
    dp[i][knapsack] = ans;
	return ans;
}
void input() {
    int n, W; cin>>n>>W;
    vi weight;
    vi values;
    while(n--) {
        int Wi, Vi; cin>>Wi>>Vi;
        weight.push_back(Wi);
        values.push_back(Vi);
    }
    vvi dp(weight.size()+1, vi(W+1, -1));
    cout<<f(weight, values, dp, W)<<endl;
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

