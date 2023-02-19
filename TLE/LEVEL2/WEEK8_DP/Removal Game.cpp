#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
const int MOD = 1e9 + 7;

// ----------------------------------------------------------------------------------------------------

// link:- https://cses.fi/problemset/task/1097

int dp[5000+1][5000+1];
int f(vi& score, int L, int R) {
    // base case
    if(L > R) return 0;
    if(dp[L][R] != -1) return dp[L][R];

    // recursive case
    int sumOfRange = score[R] - score[L-1];
    int opponent_1 = f(score, L+1, R);
    int opponent_2 = f(score, L, R-1);
    int optimal = sumOfRange - std::min(opponent_1, opponent_2);

    // store and return
    dp[L][R] = optimal;
    return optimal;
}

void input() {
    int n; cin>>n;
    vi score(n+1, 0);
    for(int i=1; i<=n; i++) {
        cin>>score[i];
        // prefix sum
        score[i] += score[i-1];
    }
    std::memset(dp, -1, sizeof dp);
    cout<<f(score, 1, n)<<endl; 
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    input();
    return 0;
}

