//https://leetcode.com/problems/subsets/submissions/
class Solution {
public:
    void f(int i, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp) {
        //baseCase
        if(i == nums.size()) {
            ans.push_back(temp);
            return;
        }
        
        //include
        temp.push_back(nums[i]);
        f(i+1, nums, ans, temp);
        
        //backtrack
        temp.pop_back();
        
        //exclude
        f(i+1, nums, ans, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(0, nums, ans, temp);
        return ans;
    }
};