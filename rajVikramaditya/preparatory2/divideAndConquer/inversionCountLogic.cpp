//https://leetcode.com/problems/reverse-pairs/
class Solution {
public:
    int merge(int low, int mid, int high, vector<int> &nums) {
        int inv = 0;
        int left = low, right = mid+1;
        for(left; left<=mid; left++) {
            while(right <= high && nums[left] > 2LL * nums[right]) right++;
            inv += (right-(mid+1));
        }
        
        vector<int> tmp;
        left = low, right = mid+1;
        while(left <= mid && right <= high) {
            if(nums[left] <= nums[right]) tmp.push_back(nums[left++]);
            else tmp.push_back(nums[right++]);
        }
        while(left <= mid) tmp.push_back(nums[left++]);
        while(right <= high) tmp.push_back(nums[right++]);
        int j=0;
        for(int i=low; i<=high; i++) nums[i] = tmp[j++];
        return inv;
    }
    int mergeSort(int low, int high, vector<int> &nums) {
        int mid, inv = 0, size = high-low+1;
        if(size > 1) {
            mid = low + (high - low)/2;
            inv += mergeSort(low, mid, nums);
            inv += mergeSort(mid+1, high, nums);
            inv += merge(low, mid, high, nums);
        }
        return inv;
    }
    int reversePairs(vector<int>& nums) {
    
        // //TLE O(N^2)
        // long long int M = 10000000000000000000+7;
        // int inversionCount = 0;
        // for(int i=0; i<nums.size()-1; i++) {
        //     for(int j=i+1; j<nums.size(); j++) {
        //         long long int prev = ((nums[j] % M) + (nums[j] % M)) % M;
        //         if(nums[i] > prev) inversionCount++;
        //     }
        // }
        // return inversionCount;
        
        //O(NlogN)
        return mergeSort(0, nums.size()-1, nums);
    }
};