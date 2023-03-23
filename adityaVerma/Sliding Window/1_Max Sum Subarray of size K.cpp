// https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
class Solution {   
public:
    long maximumSumSubarray(int K, vector<int>& Arr , int N){
        // step1
        long maxSum = INT_MIN;
        long curSum = 0;
        for(int i=0; i<K; i++) curSum += Arr[i];
        maxSum = std::max(maxSum, curSum);
        
        // step2
        int i = 0;
        int j = K;
        while(i<N && j<N) {
            curSum += Arr[j++];
            curSum -= Arr[i++];
            maxSum = std::max(maxSum, curSum);
        }
        return maxSum;
    }
};