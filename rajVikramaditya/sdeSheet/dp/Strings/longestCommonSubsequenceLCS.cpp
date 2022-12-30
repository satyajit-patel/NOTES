//https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include<bits/stdc++.h>
#define vvi vector<vector<int>>
int f(int n1, int n2, string &s1, string &s2, vvi &dp) {
    if(n1 < 0 || n2 < 0) return 0;
    if(dp[n1][n2] != -1) return dp[n1][n2];
    
    if(s1[n1] == s2[n2]) return dp[n1][n2] = 1 + f(n1-1, n2-1, s1, s2, dp);
    return dp[n1][n2] = max(f(n1-1, n2, s1, s2, dp), f(n1, n2-1, s1, s2, dp));
}
int lcs(string s, string t) {
	int n1 = s.size();
    int n2 = t.size();
    vvi dp(n1+1, vector<int>(n2+1, -1));
    return f(n1-1, n2-1, s, t, dp);
}