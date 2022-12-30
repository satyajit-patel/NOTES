//https://leetcode.com/problems/burst-balloons/submissions/
class Solution {
public:
    int partition(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxi = INT_MIN;
        for(int k=i; k<=j; k++) {
            int left = partition(i, k-1, nums, dp);
            int right = partition(k+1, j, nums, dp);
            int cost = nums[i-1] * nums[k] * nums[j+1];
            int total = left + right + cost;
            maxi = max(maxi, total);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        return partition(1, n, nums, dp);
    }
};