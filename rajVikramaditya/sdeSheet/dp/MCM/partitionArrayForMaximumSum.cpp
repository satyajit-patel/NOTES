//https://leetcode.com/problems/partition-array-for-maximum-sum/submissions/
class Solution {
public:
    int f(int i, int n, int k, vector<int> &nums, vector<int> &dp) {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        
        int maxEle = INT_MIN, maxSum = INT_MIN;
        for(int j=i; j<min(n, i+k); j++) {
            int length = j-i+1;
            maxEle = max(maxEle, nums[j]);
            int sum = (length * maxEle) + f(j+1, n, k, nums, dp);
            maxSum = max(maxSum, sum);
        }
        return dp[i] = maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return f(0, n, k, arr, dp);
    }
};