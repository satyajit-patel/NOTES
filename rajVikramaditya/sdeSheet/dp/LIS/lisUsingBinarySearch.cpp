//https://leetcode.com/problems/longest-increasing-subsequence/submissions/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        s.insert(nums[0]);
        for(int i=1; i<n; i++) {
            if(nums[i] > *s.rbegin()) s.insert(nums[i]);
            else {
                auto it = s.lower_bound(nums[i]);
                s.erase(it);
                s.insert(nums[i]);
            }
        }
        return s.size();
    }
};