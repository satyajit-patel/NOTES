//https://leetcode.com/problems/minimum-cost-to-cut-a-stick/submissions/
#define vi vector<int>
#define vvi vector<vector<int>>
class Solution {
public:
    int M = int(1e9+7);
    int partition(int i, int j, vi &cuts, vvi &dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        for(int k=i; k<=j; k++) {
            int left = partition(i, k-1, cuts, dp);
            int right = partition(k+1, j, cuts, dp);
            int cost = cuts[j+1] - cuts[i-1];
            int total = (((left %M) + (right %M) %M) + (cost %M)) %M;
            mini = min(mini, total);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int N = cuts.size();
        vvi dp(N+1, vi(N+1, -1));
        
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        
        return partition(1, N, cuts, dp);
    }
};