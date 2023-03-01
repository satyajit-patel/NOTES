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

//---------------------------------------------------------------------


// https://atcoder.jp/contests/dp/tasks/dp_c
int f(int idx, int prev, int n, vvi& arr, vvi& dp) {
    //base case
    if(idx >= n) return 0;
    if(prev != -1) {
        if(dp[idx][prev] != -1) return dp[idx][prev];
    }

    int ans = 0;
    for(int i=0; i<3; i++) {
        if(i != prev) {
            int point = arr[idx][i] + f(idx+1, i, n, arr, dp);
            ans = std::max(ans, point);
        }
    }
    if(prev != -1) dp[idx][prev] = ans;
    return ans;
}
void input() {
    int n; cin>>n;
    vvi arr(n, vi(3));
    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) cin>>arr[i][j];
    }
    vvi dp(n+1, vi(3+1, -1));
    cout<<f(0, -1, n, arr, dp)<<endl;
}

//------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

