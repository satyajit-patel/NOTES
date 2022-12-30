//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012
#include<bits/stdc++.h>
// IOS
#define     IOS     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define     int     long long int
#define     vi      vector<int>
#define     dq      deque<int>
#define     endl    "\n" 

using namespace std;

int frog(int a[], int ind, int n, int dp[])
{
    //baseCase
    if(ind == n-1) return 0;
    if(dp[ind] != -1) return dp[ind];

    //recursiveCase
    int oneJump = abs(a[ind]-a[ind+1]) + frog(a, ind+1, n, dp);
    int secondJump = INT_MAX;
    if(ind <= n-1){
        secondJump = abs(a[ind]-a[ind+2]) + frog(a, ind+2, n, dp);
    }
    return dp[ind] = min(oneJump, secondJump);
}
void solve()
{
    int tc; cin>>tc;
    while(tc--)
    {
        int n; cin>>n;
        int a[n];
        for(auto &it : a) cin>>it;
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        int ans = frog(a, 0, n, dp);
        cout<<ans<<endl;
    }
}
signed main()
{
    IOS
    solve();
    return 0;
}