// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto unSortedGuy = std::is_sorted_until(nums.begin(), nums.end());
        int pivot = unSortedGuy - nums.begin() - 1;
        if(target >= nums[0] && target <= nums[pivot]) {
            auto last = nums.begin() + pivot + 1;
            auto it   = std::find(nums.begin(), last, target);
            if(it != last) return it - nums.begin();
            return -1; 
        }
        else {
            auto start = nums.begin() + pivot + 1;
            auto it    = std::find(start, nums.end(), target);
            if(it != nums.end()) return it - nums.begin();
            return -1;
        }
    }
};