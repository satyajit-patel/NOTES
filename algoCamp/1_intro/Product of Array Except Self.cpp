// https://leetcode.com/problems/product-of-array-except-self/description/
class Solution {
public:
    std::vector<int> prefixProd(std::vector<int>& nums) {
        std::vector<int> prefix(nums.size());
        for(int i=0; i<nums.size(); i++) {
            if(i == 0) prefix[i] = nums[i];
            else prefix[i] = nums[i] * prefix[i-1];
        }
        return prefix;
    }

    std::vector<int> suffixProd(std::vector<int>& nums) {
        std::vector<int> suffix(nums.size());
        for(int i=nums.size()-1; i>=0; i--) {
            if(i == nums.size()-1) suffix[i] = nums[i];
            else suffix[i] = nums[i] * suffix[i+1];
        }
        return suffix;
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefix = prefixProd(nums);
        std::vector<int> suffix = suffixProd(nums);
        std::vector<int> ans(nums.size());
        for(int i=0; i<nums.size(); i++) {
            if(i == 0) ans[i] = suffix[i+1];
            else if(i == nums.size()-1) ans[i] = prefix[i-1];
            else ans[i] = prefix[i-1] * suffix[i+1];
        }
        return ans;
    }
};