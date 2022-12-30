//equal subset sum

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define endl "\n"
#define vii vector<vector<int>> 

int knapsack(vi &weights, vi &values, int idx, int n, int w, vii &dp) {
	if(idx == n) return 0;
	if(dp[idx][w] != -1) return dp[idx][w];
	
	int pick = INT_MIN;
	if(weights[idx] <= w) pick = values[idx] + knapsack(weights, values, idx+1, n, w-weights[idx], dp);
	return dp[idx][w] = max(pick, knapsack(weights, values, idx+1, n, w, dp));
}
int main() {
	int tc; cin>>tc;
	while(tc--) {
		int n,w; cin>>n>>w;
		vi weights(n);
		vi values(n);
		for(auto &it:weights) cin>>it;
		for(auto &it:values) cin>>it;
		vii dp(n+1, vi(w+1, -1));
		cout<<knapsack(weights, values, 0, n, w, dp)<<endl;
	}
	return 0;
}