// https://leetcode.com/problems/jump-game-ii/description/
class Solution {
public:
    int f(vector<int>& nums, vector<int>& dp, int i=0) {
        // base case
        if(i >= nums.size()-1) return 0;
        if(dp[i] != -1) return dp[i];

        int mini = 1e8, step = 0;
        for(int jump=1; jump<=nums[i]; jump++) {
            step = 1 + f(nums, dp, i+jump);
            mini = std::min(mini, step);
        }
        dp[i] = mini;
        return mini;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return f(nums, dp);
    }
};