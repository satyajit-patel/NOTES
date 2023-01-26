// https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1
class Solution{
    public:
    int circularSubarraySum(int arr[], int num){
        
        int totSum = 0;
        for(int i=0; i<num; i++) totSum += arr[i];
        
        // kadane
        int sum = 0, maxSum = INT_MIN;
        for(int i=0; i<num; i++) {
            sum += arr[i];
            maxSum = std::max(maxSum, sum);
            if(sum < 0) sum = 0;
        }
        
        // reverse kadane (prefix + suffix)
        int curSum = 0, minSum = INT_MAX;
        for(int i=0; i<num; i++) {
            curSum += arr[i];
            minSum = std::min(minSum, curSum);
            if(curSum > 0) curSum = 0;
        }
        
        // edge case : if A.size == 1 && Ai = -8 then we have to return -8
        if(maxSum < 0) return maxSum;
        
        // array = prefix + subarray + suffix
        // i.e subarray = totSum - (prefix + suffix)
        int subarray = totSum - minSum;
        return std::max(subarray, maxSum);
    }
};