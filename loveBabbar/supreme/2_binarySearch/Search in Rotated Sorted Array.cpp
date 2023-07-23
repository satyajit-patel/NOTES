// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
class Solution {
public:
    bool predicate2(int i, const vector<int>& arr, int target) {
        return arr[i] <= target;
    }

    int my_binary_search(int L, int H, const vector<int>& nums, int target) {
        while(H-L > 1) {
            int M = L + (H-L)/2;
            predicate2(M, nums, target) ? (L = M) : (H = M);
        }
        return L;
    }

    int find_pivot(const vector<int>& arr) {
        int L = -1, H = arr.size();
        while(H-L > 1) {
            int mid = L + (H-L)/2;
            // we need to handle only 2 element who are breaking the law
            // and find first element betwwen them
            if(mid+1 < arr.size() && arr[mid] > arr[mid+1]) return mid; // for element 1
            if(mid-1 >= 1 && arr[mid-1] > arr[mid]) return mid-1; // for element 2
            if(arr[0] <= arr[mid]) L = mid;
            else H = mid;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot = find_pivot(nums);
        if(pivot == -1) {
            int L = my_binary_search(-1, nums.size(), nums, target);
            if(L != -1 && nums[L] == target) return L;
        }
        else if(target >= nums[0] && target <= nums[pivot]) {
            int L = my_binary_search(-1, pivot+1, nums, target);
            if(L != -1 && nums[L] == target) return L;
        }
        else {
            int L = my_binary_search(pivot, nums.size(), nums, target);
            if(L != pivot && nums[L] == target) return L;
        }
        return -1;
    }
};