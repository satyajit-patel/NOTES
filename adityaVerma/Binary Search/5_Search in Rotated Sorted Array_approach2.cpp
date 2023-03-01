// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
class Solution {
public:
    int bs(int L, int H, vector<int>& nums, int target) {
        while(H-L > 1) {
            int mid = L + (H-L)/2;
            if(nums[mid] == target) return mid;
            (nums[mid] < target) ? (L = mid) : (H = mid);
        }
        return -1;
    }

    int findPivot(vector<int>& nums) {
        int n = nums.size();
        int L = -1, H = n;
        while(H-L > 1) {
            int mid = L + (H-L)/2;
            if(mid+1 < n && nums[mid] > nums[mid+1]) return mid;
            if(mid-1 > 0 && nums[mid] < nums[mid-1]) return mid-1;
            (nums[0] <= nums[mid]) ? (L = mid) : (H = mid);
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums);
        if(pivot == -1) pivot = n-1;
        if(target >= nums[0] && target <= nums[pivot]) return bs(-1, pivot+1, nums, target);
        else return bs(pivot, n, nums, target);
    }
};