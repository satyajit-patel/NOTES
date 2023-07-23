// link => https://atcoder.jp/contests/dp/tasks/dp_c
#include<bits/stdc++.h>
using namespace std;
// -------------------------------------------------------------------------------------------

// global variable
vector<vector<int>> A, dp;

int f(int n, int prev) {
    // base case
    if(n < 0) return 0;
    if(prev != -1) if(dp[n][prev] != -1) return dp[n][prev];
    
    // recursive case
    int maxi = INT_MIN;
    for(int i=0; i<3; i++) if(i != prev) maxi = max(maxi, A[n][i] + f(n-1, i));
    
    // return case
    if(prev != -1) dp[n][prev] = maxi;
    return maxi;
}

void input() {
    int n; cin>>n;
    A.resize(n, vector<int>(3)), dp.resize(n, vector<int>(3, -1));
    for(auto &row : A) for(auto &it : row) cin>>it;
    cout<<f(n-1, -1)<<"\n";
}

// -------------------------------------------------------------------------------------------
int main() {
	input();
	return 0;
}
