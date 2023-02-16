#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>

// ----------------------------------------------------------------------------------------------------

// link:- https://cses.fi/problemset/task/1639

int f(string& s1, string& s2, vector<vector<int>>& dp, int i=0, int j=0) {
    // base case
    if(i >= s1.size()) return s2.size() - j;
    if(j >= s2.size()) return s1.size() - i;
    if(dp[i][j] != -1) return dp[i][j];
    
    // choice
    int include = 0, exclude = 0;
    if(s1[i] != s2[j]) {
        int add = 1 + f(s1, s2, dp, i, j+1);
        int rem = 1 + f(s1, s2, dp, i+1, j);
        int rep = 1 + f(s1, s2, dp, i+1, j+1);
        include = std::min(add, std::min(rem, rep));
    }
    else exclude =  0 + f(s1, s2, dp, i+1, j+1);

    int optimal = include + exclude;
    dp[i][j] = optimal;
    return optimal;
}

void input() {
    string s1,s2; cin>>s1>>s2;
    vector<vector<int>> dp(5000+1, vector<int>(5000+1, -1));
    cout<<f(s1, s2, dp)<<endl;
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    input();
    return 0;
}

