// https://leetcode.com/problems/3sum/description/
class Solution {
private:
    void twoSum(int prevIndex, vector<int>& nums, std::vector<std::vector<int>>& ans) {
        int i = prevIndex+1, j = nums.size()-1;
        while(i < j) {
            int sum = nums[prevIndex] + nums[i] + nums[j];
            if(sum < 0) i++;
            else if(sum > 0) j--;
            else {
                std::vector<int> temp;
                temp.push_back(nums[prevIndex]);
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                ans.push_back(temp);
                while(i < j && nums[i] == temp[1]) i++;
                while(i < j && nums[j] == temp[2]) j--;
            }
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            twoSum(i, nums, ans);
            while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};