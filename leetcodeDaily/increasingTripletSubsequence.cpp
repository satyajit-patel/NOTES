//https://leetcode.com/problems/increasing-triplet-subsequence/submissions/
class Solution {
public:    
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        
        set<int> s;
        s.insert(nums[0]);
        int len = 1;
        for(int i=1; i<n; i++) {
            if(nums[i] > *s.rbegin()) {
                s.insert(nums[i]);
                len++;
            }
            else {
                auto it = s.lower_bound(nums[i]);
                s.erase(it);
                s.insert(nums[i]);
            }
        }
        //return s.size();
        return (len >= 3); //will take less time than s.size();
    }
};