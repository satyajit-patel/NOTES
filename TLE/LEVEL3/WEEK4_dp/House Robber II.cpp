// https://leetcode.com/problems/house-robber-ii/description/
class Solution {
public:
    int f(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<n; i++) dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> A, B;
        for(int i=0; i<n-1; i++) A.push_back(nums[i]);
        for(int i=1; i<n; i++) B.push_back(nums[i]);
        return max(f(A), f(B));
    }
};