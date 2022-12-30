#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>

vi arr(100000009);
int dp[100000009];
int n,k;
int frog2(int idx) {
	if(idx == n-1) return 0;
	if(dp[idx] != -1) return dp[idx];
	
	int ans = INT_MAX;
	for(int i=1; i<=k; i++) {
		if(idx+i > n-1) break;
		ans = min(ans, abs(arr[idx]-arr[idx+i])+frog2(idx+i));
	}
	return dp[idx] = ans;
}
signed main() {
	cin>>n>>k;
	for(int i=0; i<n; i++) cin>>arr[i];
	memset(dp, -1, sizeof(dp));
	cout<<frog2(0)<<endl;
	return 0;
}