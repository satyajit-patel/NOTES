#include<bits/stdc++.h>
using namespace std;


#define log(args...)    { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << endl;
    err(++it, args...);
}




#define     IOS     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define     endl    "\n" 
#define     int     long long int
#define     vi      vector<int>
#define     vvi     vector<vector<int>>
#define     vvc     vector<vector<char>>
#define     vpi     vector<pair<int, int>>
#define     M       (int)1e9+7

int sub(int x, int y) {
    x %= M;
    y %= M;
    int ans = x - y;
    return (ans < 0) ? ans+M : ans;
}

//---------------------------------------------------------------------

// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/T

int nCr(int n,int r, vvi& dp) {
    if(r > n) return 0;
    if(r == 0 || r == n) return 1;
    if(dp[n][r] != -1) return dp[n][r];

    int ans =  nCr(n-1, r, dp) + nCr(n-1, r-1, dp);
    dp[n][r] = ans;
    return ans;
}
void input() {
    int n,r; cin>>n>>r;
    vvi dp(n+1, vi(r+1, -1));
    cout<<nCr(n, r, dp)<<endl;
}

//------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

