
//https://atcoder.jp/contests/dp/tasks/dp_a


#include<bits/stdc++.h>
using namespace std;
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
#define     IOS     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define     int     long long int
#define     vi      vector<int>
#define     endl    "\n" 
void contestSolve() {
    int tc; cin>>tc;
    while(tc--) {
        
    }
}

//approach of DP:-
		//try all ways(i.e recursion)
		//and take minimum of all ways
//approach of Recursion:-
	//give index to blackBox(function) and ask him to return the cost
	//and give him a baseCase i.e what only you know
	//tumhe jitna pata hai bo karo aur baki Recursion ko bolo karne
int fun(vi &arr, int i, int n, vi &dp) {
	if(i == n-1) return 0;
	if(dp[i] != -1) return dp[i];

	
	int oneStep = abs(arr[i]-arr[i+1]) + fun(arr, i+1, n, dp);
	int twoStep = INT_MAX; 
	if(i <= n-1) twoStep = abs(arr[i]-arr[i+2]) + fun(arr, i+2, n, dp);
	return dp[i] = min(oneStep, twoStep);
}
void normalSolve() {
	int  n; cin>>n;
	vi arr(n);
	for(auto &it:arr) cin>>it;
	vi dp(n+1, -1);
	cout<<fun(arr, 0, n, dp);
}
signed main() {
    IOS
    //contestSolve()
    normalSolve();
    return 0;
}
