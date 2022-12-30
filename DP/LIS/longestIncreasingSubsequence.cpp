// https://leetcode.com/problems/longest-increasing-subsequence/description/
class Solution {
public:
    int f(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        // base case
        if(i == nums.size()) return 0;
        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];

        // include
        int incl = 0;
        if(prev == -1 || nums[i] > nums[prev]) incl = 1 + f(i+1, i, nums, dp);

        // exclude
        int excl = 0 + f(i+1, prev, nums, dp);

        int ans = std::max(incl, excl);
        dp[i][prev + 1] = ans;
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        return f(0, -1, nums, dp);
    }
};