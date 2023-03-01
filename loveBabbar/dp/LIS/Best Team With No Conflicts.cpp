// https://leetcode.com/problems/best-team-with-no-conflicts/description/
class Solution {
public:
    int f(vector<pair<int, int>>& nums, vector<vector<int>> &dp, int i, int prev) {
        if(i == nums.size()) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];

        // include
        int incl = 0;
        if(prev == nums.size() || nums[i].second >= nums[prev].second) incl = nums[i].second + f(nums, dp, i+1, i);

        // exclude
        int excl = 0 + f(nums, dp, i+1, prev);

        int ans = std::max(incl, excl);
        dp[i][prev] = ans;
        return ans;
    }
    int LIS(vector<pair<int, int>>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        return f(nums, dp, 0, nums.size());
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> nums;
        for(int i=0; i<scores.size(); i++) nums.push_back({ages[i], scores[i]});
        std::sort(nums.begin(), nums.end());
        return LIS(nums);
    }
};