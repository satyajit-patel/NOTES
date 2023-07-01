// https://leetcode.com/problems/subarray-sum-equals-k/description/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> hashMap;
        int count = 0, sum = 0;
        for(int i=0; i<nums.size(); i++) {
            hashMap[sum]++;
            sum += nums[i];
            if(hashMap.count(sum-k)) count += hashMap[sum-k];
        }
        return count;
    }
};