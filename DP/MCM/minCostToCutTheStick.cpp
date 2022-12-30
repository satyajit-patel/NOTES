// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/
class Solution {
public:
    int add(int a, int b) {
        int M = (int)1e9+7;
        return ((a%M) + (b%M))%M;
    }
    int f(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
        // base case
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for(int k=i; k<=j; k++) {
            int left    = f(i, k-1, arr, dp);
            int right    = f(k+1, j, arr, dp);
            int cost    = arr[j+1] - arr[i-1];
            int total   = add(left, add(right, cost));
            ans = std::min(ans, total);
        }
        dp[i][j] = ans;
        return ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int actualSize = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        std::sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size()+1, vector<int>(cuts.size()+1, -1));
        return f(1, actualSize, cuts, dp);
    }
};