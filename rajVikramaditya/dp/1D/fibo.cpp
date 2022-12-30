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
int fibo(int n, vi &dp) {
	if(n <= 1) return n;
	if(dp[n] != -1) return dp[n];

	return dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
}
void normalSolve() {
	int  n=5;
	vi dp(n+1, -1); //becz if you declared dp of size 4, you won't have the index for 4 itself so N+1
	cout<<fibo(n, dp);
}
signed main() {
    IOS
    //contestSolve()
    normalSolve();
    return 0;
}
