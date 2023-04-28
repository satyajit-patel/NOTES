// https://leetcode.com/problems/maximum-subarray/description/
class Solution {
public:
    int kadane(vector<int>& arr) {
        int maxi = 0, curSum = 0, startIndex = 0, endIndex = 0;
        for(int i=0; i<arr.size(); i++) {
            curSum += arr[i];

            // not worth it to take
            if(curSum < 0) {
                curSum = 0;
                startIndex = i+1;
            }

            if(curSum > maxi) {
                maxi = curSum;
                endIndex = i;
            }
        }
        // max subarray is
        for(int i=startIndex; i<=endIndex; i++) cout<<arr[i]<<" ";
        return maxi;
    }
    int maxSubArray(vector<int>& nums) {
        int maxi = *std::max_element(nums.begin(), nums.end());
        if(maxi < 0) return maxi;
        return kadane(nums);
    }
};