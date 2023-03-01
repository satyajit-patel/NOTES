// https://leetcode.com/problems/target-sum/description/
class Solution {
public:
    int f(vector<int>& nums, int sum, vector<vector<int>>& dp, int i=0) {
        // base case
        if(i >= nums.size()) return sum == 0;
        if(sum < 0) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];

        // choice
        int include = 0, exclude = 0;
        if(nums[i] <= sum) include = f(nums, sum-nums[i], dp, i+1);
        exclude = f(nums, sum, dp, i+1);

        int optimal = include + exclude;
        dp[i][sum]  = optimal;
        return optimal;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
            s1 - s2 = diff
            (totSum - s2) - s2 = diff
            totSum - 2s2 = diff
            totSum - diff = 2 * s2
            s2 = (totSum - diff) / 2;
            i.e sum = (totSum - diff) / 2;
        */
        int totSum = 0;
        for(auto &it : nums) totSum += it;
        if((totSum-target)%2) return 0;
        int sum = (totSum - target) / 2;
        vector<vector<int>> dp(20+1, vector<int>(1000+1, -1));
        return f(nums, sum, dp);
    }
};