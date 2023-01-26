// https://leetcode.com/problems/longest-common-subsequence/description/
class Solution {
public:
    string printLCS(string& text1, string& text2, vector<vector<int>>& dp) {
        int n = text1.size();
        int m = text2.size();
        deque<char> dq;
        while(n>0 && m>0) {
            if(text1[n-1] == text2[m-1]) {
                dq.push_front(text1[n-1]);
                n--;
                m--;
            }
            else {
                if(dp[n-1][m] > dp[n][m-1]) n--;
                else m--;
            }
        }
        string lcs = "";
        for(auto &it : dq) lcs += it;
        return lcs;
    }
    pair<int, string> LCS(string& text1, string& text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        //baseCase
        for(int j=0; j<=m; j++) dp[0][j] = 0;
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        
        //recursiveCase
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
        pair<int, string> ans;
        ans.first = dp[n][m];
        ans.second = printLCS( text1, text2, dp);
        return ans;
    }
    int longestCommonSubsequence(string& text1, string& text2) {
        pair<int, string> ans = LCS(text1, text2);
        cout<<ans.second<<endl;
        return ans.first;
    }
};