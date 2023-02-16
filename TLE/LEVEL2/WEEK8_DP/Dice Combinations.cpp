#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
const int MOD = 1e9 + 7;

// ----------------------------------------------------------------------------------------------------

// link:- https://cses.fi/problemset/task/1633

vi dp;
int f(int n) {
    // base case 
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];

    // count summation
    int sum = 0;
    for(int i=1; i<=6; i++) sum = (sum + f(n-i)) % MOD;

    // store and return
    dp[n] = sum;
    return sum;
}

void input() {
    int n; cin>>n;
    dp.resize(1000000+1, -1);
    cout<<f(n)<<endl;
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    input();
    return 0;
}

