#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
const int MOD = 1e9 + 7;

// ----------------------------------------------------------------------------------------------------

// link:- https://atcoder.jp/contests/dp/tasks/dp_f


void input() {
    string s1,s2; cin>>s1>>s2;
    int N = s1.size();
    int M = s2.size();
    int dp[N+1][M+1];
    // base case
    for(int i=0; i<=N; i++) dp[i][0] = 0;
    for(int j=0; j<=M; j++) dp[0][j] = 0;
    
    // tabulation
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
        }
    }
    
    // print
    string lcs = "";
    while(N>0 && M>0) {
        if(s1[N-1] == s2[M-1]) {
            lcs += s1[N-1];
            N--;
            M--;
        }
        else {
            if(dp[N][M-1] > dp[N-1][M]) M--;
            else N--;
        }
    }
    std::reverse(lcs.begin(), lcs.end());
    cout<<lcs<<endl;
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    input();
    return 0;
}

