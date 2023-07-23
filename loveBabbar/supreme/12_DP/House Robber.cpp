// https://leetcode.com/problems/house-robber/description/
class Solution {
private:
    std::vector<int> dp, nums;
    int f(int n) {
        // base case
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];

        // recursive case
        int incl = this->nums[n] + f(n-2);
        int excl = 0 + f(n-1);

        // work case
        int ans = std::max(incl, excl);

        // return case
        dp[n] = ans;
        return ans;
    }
public:
    int rob(vector<int>& nums) {
        dp.resize(nums.size()+1, -1);
        this->nums = nums;
        return f(nums.size()-1);
    }
};