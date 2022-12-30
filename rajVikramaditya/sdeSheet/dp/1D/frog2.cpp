//https://atcoder.jp/contests/dp/tasks/dp_b

#include<bits/stdc++.h>
using namespace std;
#define log(args...)    { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
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
#define		vvi		vector<vector<int>>
void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

//---------------------------------------------------------------------
















int f(int n, vector<int> &nums, int k, vector<int> &dp) {
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    
    int minStep = INT_MAX, jumpEnergy;
    for(int i=1; i<=k; i++) {
        if(n-i >= 0) jumpEnergy = abs(nums[n]-nums[n-i]) + f(n-i, nums, k, dp);
        minStep = min(minStep, jumpEnergy); 
    }
    return dp[n] = minStep;
}
int frogJumpK(int n, vector<int> &nums, int k) {
    vector<int> dp(n+1, -1);
    return f(n-1, nums, k, dp);
}
 
void input() {
    int n; cin>>n;
    int k; cin>>k;
    vector<int> nums(n);
    for(int &it : nums) cin>>it;
    cout<<frogJumpK(n, nums, k)<<endl;
}












































//------------------------------------------------------------------------
signed main() {
    IOS
    init_code();
    input();
    return 0;
}









