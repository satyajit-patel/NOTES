// link => https://atcoder.jp/contests/dp/tasks/dp_a
#include<bits/stdc++.h>
using namespace std;
// -------------------------------------------------------------------------------------------

// global variable
vector<int> A, dp;

int f(int n) {
    // base case
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    
    // recursive case
    int case1 = abs(A[n]-A[n-1]) + f(n-1);
    int case2 = 1e9;
    if(n-2 >= 0) case2 = abs(A[n]-A[n-2]) + f(n-2);
    
    // work case
    int ans = min(case1, case2);
    
    // return case
    dp[n] = ans;
    return ans;
}

void input() {
    int n; cin>>n;
    A.resize(n), dp.resize(n, -1);
    for(auto &it : A) cin>>it;
    cout<<f(n-1)<<"\n";
}

// -------------------------------------------------------------------------------------------
int main() {
	input();
	return 0;
}
