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
#define     dq      deque<int>
#define     vi      vector<int>
#define     vvi     vector<vector<int>>
void sublimeText() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

//---------------------------------------------------------------------

int fiboRec(int n, int &functionEnteredInrec) {
    functionEnteredInrec++;
    if(n <= 1) return n;
    return fiboRec(n-1, functionEnteredInrec) + fiboRec(n-2, functionEnteredInrec);
}
int fiboDp(int n, int &functionEnteredInDp, vi &dp) {
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    functionEnteredInDp++;
    return dp[n] = fiboDp(n-1, functionEnteredInDp, dp) + fiboDp(n-2, functionEnteredInDp, dp);
}
void input() {
    int n = 19;
    int functionEnteredInrec = 0;
    int functionEnteredInDp = 0;
    int ans1 = fiboRec(n, functionEnteredInrec); 
    cout<<ans1<<" "<<functionEnteredInrec<<endl;
    vi dp(n+1, -1);
    int ans2 = fiboDp(n, functionEnteredInDp, dp);
    cout<<ans2<<" "<<functionEnteredInDp<<endl;
}

//------------------------------------------------------------------------
signed main() {
    IOS
    sublimeText();
    input();
    return 0;
}