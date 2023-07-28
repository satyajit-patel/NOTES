//https://leetcode.com/problems/3sum-closest/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<int> s;
        for(int i=0; i<n-2; i++) {
            int newTarget = nums[i];
            int low = i+1, high = n-1;
            while(low < high) {
                int twoSum = nums[low] + nums[high] + newTarget;
                if(twoSum == target) return twoSum;
                s.insert(twoSum);
                if(twoSum < target) low++;
                else high--;
            }
        }
        if(s.upper_bound(target) != s.end()) return *s.upper_bound(target);
        return *s.rbegin();
    }
};