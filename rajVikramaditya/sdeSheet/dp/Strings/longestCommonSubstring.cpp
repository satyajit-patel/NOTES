//https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include <bits/stdc++.h> 
int lcs(string &text1, string &text2){
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    //baseCase
    for(int j=0; j<=m; j++) dp[0][j] = 0;
    for(int i=0; i<=n; i++) dp[i][0] = 0;

    //recursiveCase
    int maxi = 0; //bcz there will be cases when nothing will match so zero length
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(text1[i-1] == text2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                maxi = max(maxi, dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    return maxi;
}