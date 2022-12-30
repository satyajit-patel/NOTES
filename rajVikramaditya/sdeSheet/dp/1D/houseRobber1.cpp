//https://bit.ly/3q5rlUY
#include <bits/stdc++.h> 
int ms(int n, vector<int> &nums, vector<int> &dp) {
    if(n == 0) return nums[n];
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];
    
    int pick = nums[n] + ms(n-2, nums, dp);
    int notPick = 0 + ms(n-1, nums, dp);
    return dp[n] = max(pick, notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size()+1, -1);
    return ms(nums.size()-1, nums, dp);
}