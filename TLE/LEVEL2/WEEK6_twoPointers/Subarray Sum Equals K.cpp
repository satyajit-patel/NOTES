// https://leetcode.com/problems/subarray-sum-equals-k/description/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int length = 0;
        std::map<int, int> map;
        for(int i=1; i<nums.size(); i++) nums[i] += nums[i-1];
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == k) length++;
            if(map.count(nums[i]-k)) length += map[nums[i]-k];
            map[nums[i]]++;
        }
        return length;
    }
};