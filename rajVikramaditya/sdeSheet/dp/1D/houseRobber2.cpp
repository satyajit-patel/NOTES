//https://leetcode.com/problems/house-robber-ii/submissions/
class Solution {
public:   
    int hr2(int n, vector<int> &nums2, vector<int> &dp2) {
        if(n == 0) return nums2[n];
        if(n < 0) return 0;
        if(dp2[n] != -1) return dp2[n];

        int pick = nums2[n] + hr2(n-2, nums2, dp2);
        int notPick = 0 + hr2(n-1, nums2, dp2);
        return dp2[n] = max(pick, notPick);
    }
    int hr1(int n, vector<int> &nums1, vector<int> &dp1) {
        if(n == 0) return nums1[n];
        if(n < 0) return 0;
        if(dp1[n] != -1) return dp1[n];

        int pick = nums1[n] + hr1(n-2, nums1, dp1);
        int notPick = 0 + hr1(n-1, nums1, dp1);
        return dp1[n] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> nums1, nums2;
        vector<int> dp1(n+1, -1), dp2(n+1, -1);
        for(int i=0; i<n; i++) {
            if(i != 0) nums1.push_back(nums[i]);
            if(i != n-1) nums2.push_back(nums[i]);
        }
        return max(hr1(nums1.size()-1, nums1, dp1), hr2(nums2.size()-1, nums2, dp2));
    }
};

















//https://www.codingninjas.com/codestudio/problems/house-robber_839733?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h> 
long long int hr2(int n, vector<int> &nums2, vector<long long int> &dp2) {
    if(n == 0) return nums2[n];
    if(n < 0) return 0;
    if(dp2[n] != -1) return dp2[n];
    
    long long int pick = nums2[n] + hr2(n-2, nums2, dp2);
    long long int notPick = 0 + hr2(n-1, nums2, dp2);
    return dp2[n] = max(pick, notPick);
}
long long int hr1(int n, vector<int> &nums1, vector<long long int> &dp1) {
    if(n == 0) return nums1[n];
    if(n < 0) return 0;
    if(dp1[n] != -1) return dp1[n];
    
    long long int pick = nums1[n] + hr1(n-2, nums1, dp1);
    long long int notPick = 0 + hr1(n-1, nums1, dp1);
    return dp1[n] = max(pick, notPick);
}
long long int houseRobber(vector<int>& valueInHouse) {
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];
    vector<int> nums1, nums2;
    vector<long long int> dp1(n+1, -1), dp2(n+1, -1);
    for(int i=0; i<n; i++) {
        if(i != 0) nums1.push_back(valueInHouse[i]);
        if(i != n-1) nums2.push_back(valueInHouse[i]);
    }
    return max(hr1(nums1.size()-1, nums1, dp1), hr2(nums2.size()-1, nums2, dp2));
}