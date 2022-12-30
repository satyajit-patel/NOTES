//https://leetcode.com/problems/minimum-size-subarray-sum/submissions/
class Solution {
public:
    bool blackBox2(int k, vector<int> &arr, int target) {
        int i=0, j=0, sum = 0, ans = 0;
        while(j < arr.size()) {
            sum += arr[j];
            if(j-i+1 < k) {
                j++;
                continue;
            }
            if(j-i+1 == k) {
                if(sum > ans) ans = sum;
                sum -= arr[i];
                i++;
                j++;
            }
        }
        return ans >= target;
    }
    bool blackBox(int k, vector<int> &arr, int target) {
        int low = 0, high = k-1, sum = 0;
        for(int i=0; i<k; i++) sum += arr[i];
        int ans = sum;
        //slider
        while(high < arr.size()-1) {
            sum -= arr[low++];
            sum += arr[++high];
            if(sum > ans) ans = sum;
        }
        return ans >= target;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 1, high = nums.size()+1, ans = 0;
        while(low < high) {
            int mid = (low + high)/2;
            if(blackBox2(mid, nums, target)) {
                ans = mid;
                high = mid;
            }
            else low = mid+1;
        }
        return ans;
    }
};