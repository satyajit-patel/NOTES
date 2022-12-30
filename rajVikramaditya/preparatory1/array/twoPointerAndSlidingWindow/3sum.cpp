//https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            int low=i+1, high=n-1;
            int newTarget = nums[i];
            while(low < high) {
                int twoSum = nums[low]+nums[high]+newTarget;
                if(twoSum < 0) low++;
                else if(twoSum > 0) high--;
                else {
                    vector<int> tmp(3);
                    tmp[0] = nums[i];
                    tmp[1] = nums[low];
                    tmp[2] = nums[high];
                    ans.push_back(tmp);
                    
                    //skip the duplicates
                    while(low < high && nums[low] == tmp[1]) low++;
                    while(low < high && nums[high] == tmp[2]) high--;
                }
            }
            while(i+1 < n && nums[i+1] == nums[i]) i++;
        }
        return ans;
    }
};