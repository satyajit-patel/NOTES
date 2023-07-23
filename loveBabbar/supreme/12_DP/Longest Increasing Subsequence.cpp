// https://leetcode.com/problems/longest-increasing-subsequence/description/
class Solution {
private:
    vector<int> nums;
    vector<vector<int>> dp;
    int f(int i, int prev) {
        // base case
        if(i >= nums.size()) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];

        // recursive case
        int incl = 0;
        if(prev == 1e4 || nums[i] > nums[prev]) {
            int ans = f(i+1, i);
            incl = std::max(incl, 1+ans);
        }
        int excl = f(i+1, prev);

        int ans = std::max(incl, excl);
        dp[i][prev] = ans;
        return ans;
    }
public:
    int lengthOfLIS(vector<int>& _nums) {
        nums = _nums;
        dp.resize(nums.size()+1, vector<int>(1e4+1, -1));
        return f(0, 1e4);
    }
};