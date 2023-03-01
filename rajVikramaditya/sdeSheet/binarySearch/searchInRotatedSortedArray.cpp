//https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(target == nums[mid]) return mid;
            if(nums[low] <= nums[mid]) { //i.e left part is sorted
                if(target >= nums[low] && target <= nums[mid]) high = mid-1;
                else low = mid+1;
            }
            else { //i.e right part is sorted
                if(target >= nums[mid] && target <= nums[high]) low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
    }
};