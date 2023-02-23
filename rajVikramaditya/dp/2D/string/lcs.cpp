#include<bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>>
#define vi vector<int>

int lcs(string s1, string s2, int i, int j, int n, int m, vii &dp) {
	if(i >= n || j >= m) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	
	int match = 0;
	int notMatch = 0;
	if(s1[i] == s2[j]) match = 1 + lcs(s1, s2, i+1, j+1, n, m, dp);
	else notMatch = max(lcs(s1,s2,i+1,j,n,m,dp), lcs(s1,s2,i,j+1,n,m,dp));
	// return dp[i][j] = max(match, notMatch);
	return dp[i][j] = match + notMatch;
}
int main() {
	string s1,s2; cin>>s1>>s2;
	int n = s1.size();
	int m = s2.size();
	vii dp(n+1, vi(m+1, -1));
	cout<<lcs(s1, s2, 0, 0, n, m, dp)<<"\n";
	return 0;
}