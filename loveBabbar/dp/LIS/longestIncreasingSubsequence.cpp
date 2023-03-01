// https://leetcode.com/problems/longest-increasing-subsequence/description/
class Solution {
public:
    int f(vector<int>& nums, vector<vector<int>>& dp, int i=0, int prev=1e4) {
        // base case
        if(i == nums.size()) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];

        // include
        int incl = 0;
        if(prev == 1e4 || nums[i] > nums[prev]) incl = 1 + f(nums, dp, i+1, i);

        // exclude
        int excl = 0 + f(nums, dp, i+1, prev);

        int ans = std::max(incl, excl);
        dp[i][prev] = ans;
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        /* 
            1 <= nums.length <= 2500
            -104 <= nums[i] <= 104
        */
        vector<vector<int>> dp(nums.size()+1, vector<int>(1e4+1, -1));
        return f(nums, dp);
    }
};