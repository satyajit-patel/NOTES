// https://leetcode.com/problems/partition-equal-subset-sum/description/
class Solution {
private:
    std::vector<int> nums;
    std::vector<std::vector<int>> dp;
    bool f(int n, int target) {
        // base case
        if(target == 0) return true;
        if(target < 0) return false;
        if(n < 0) return target == 0;
        if(dp[n][target] != -1) return dp[n][target];

        // recursive case
        bool incl = f(n-1, target-this->nums[n]);
        bool excl = f(n-1, target);

        // work case
        bool ans = incl || excl;

        // return case
        dp[n][target] = ans;
        return ans;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto &it : nums) sum += it;
        if(sum & 1) return false;
        this->nums = nums;
        dp.resize(nums.size()+1, std::vector<int>(sum+1, -1));
        return f(nums.size()-1, sum/2);
    }
};