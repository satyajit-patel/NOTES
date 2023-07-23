// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        if(binary_search(nums.begin(), nums.end(), target)) {
            auto it1 = lower_bound(nums.begin(), nums.end(), target);
            auto it2 = upper_bound(nums.begin(), nums.end(), target);
            ans[0] = it1 - nums.begin(); 
            ans[1] = it2 - nums.begin() - 1;
        }
        return ans;
    }
};