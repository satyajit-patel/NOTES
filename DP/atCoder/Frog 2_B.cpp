// link => https://atcoder.jp/contests/dp/tasks/dp_b
#include<bits/stdc++.h>
using namespace std;
// -------------------------------------------------------------------------------------------

// global variable
int k;
vector<int> A, dp;

int f(int n) {
    // base case
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    
    // recursive case
    int mini = INT_MAX;
    for(int i=1; i<=k; i++) if(n-i >= 0) mini = min(mini, abs(A[n]-A[n-i]) + f(n-i));
    
    // return case
    dp[n] = mini;
    return mini;
}

void input() {
    int n; cin>>n>>k;
    A.resize(n), dp.resize(n, -1);
    for(auto &it : A) cin>>it;
    cout<<f(n-1)<<"\n";
}

// -------------------------------------------------------------------------------------------
int main() {
	input();
	return 0;
}
