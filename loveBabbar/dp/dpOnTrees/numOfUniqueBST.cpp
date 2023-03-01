//https://leetcode.com/problems/unique-binary-search-trees/
class Solution {
public:
    int f(int n, vector<int>& dp) {
        //base case
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        
        int ans = 0;
        for(int i=1; i<=n; i++) {
            int leftsOfNode = f(i-1, dp);
            int rightsOfNode = f(n-i, dp);
            ans += leftsOfNode * rightsOfNode;
        }
        
        dp[n] = ans;
        return ans;
    }
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};