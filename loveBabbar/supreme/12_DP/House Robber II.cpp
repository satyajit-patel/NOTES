// https://leetcode.com/problems/house-robber-ii/description/
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
        // edge case
        if(nums.size() == 1) return nums[0];

        // case1
        dp.resize(nums.size()+1, -1);
        this->nums.insert(this->nums.begin(), nums.begin(), nums.end()-1);
        int case1 = f(this->nums.size()-1);

        dp.clear();
        this->nums.clear();

        // case2
        dp.resize(nums.size()+1, -1);
        this->nums.insert(this->nums.begin(), nums.begin()+1, nums.end());
        int case2 = f(this->nums.size()-1);

        return std::max(case1, case2);
    }
};