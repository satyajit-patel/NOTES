#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>

// ----------------------------------------------------------------------------------------------------

// link:- https://cses.fi/problemset/task/1637

int f(int n, vector<int>& dp) {
    // base case
    if(n <= 0) return 0;
    if(dp[n] != -1) return dp[n];

    // choice
    int optimal = INT_MAX;
    string s = std::to_string(n);
    for(auto &it : s) {
        int digit = it - '0';
        if(digit != 0) optimal = std::min(optimal, 1 + f(n - digit, dp));
    }

    dp[n] = optimal;
    return optimal;
}

void input() {
    int n; cin>>n;
    vector<int> dp(n+1, -1);
    cout<<f(n, dp)<<endl;
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    input();
    return 0;
}

