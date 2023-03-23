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
#define		vii		vector<vector<int>>
void contestSolve() {
    int tc; cin>>tc;
    while(tc--) {
        
    }
}
int go(vii &mat, int i, int j, int n, int m, vii &dp) {
	if(i >= n || j >= m) return INT_MIN;
	if(i == n-1 && j == m-1) return mat[i][j];
	if(dp[i][j] != -1) return dp[i][j];

	int sum = mat[i][j];
	sum += max(go(mat, i+1, j, n, m, dp), go(mat, i, j+1, n, m, dp));
	return dp[i][j] = sum;
}
void normalSolve() {
	int n,m; cin>>n>>m;
	vii mat(n, vi(m));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>mat[i][j];
		}
	}
	vii dp(n+1, vi(m+1, -1));
	cout<<go(mat, 0, 0, n, m, dp)<<endl;
}
signed main() {
    IOS
    //contestSolve()
    normalSolve();
    return 0;
}
