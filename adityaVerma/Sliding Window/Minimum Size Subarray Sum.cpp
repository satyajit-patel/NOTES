// https://leetcode.com/problems/minimum-size-subarray-sum/description/
class Solution {
public:
    bool predicate(int mid, int target, vector<int>& nums) {
        int i = 0, j = 0, sum = 0;
        while(j < nums.size()) {
            sum += nums[j];
            if(j-i+1 < mid) j++;
            else if(j-i+1 == mid) {
                if(sum >= target) return true;
                sum -= nums[i];
                i++;
                j++;
            }
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0, high = nums.size()+1;
        bool flag = false;
        while(high-low >= 2) {
            int mid = (low + high) / 2;
            predicate(mid, target, nums) ? high = mid, flag = true : low = mid;
        }
        if(flag) return high;
        return 0;
    }
};