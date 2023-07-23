// https://leetcode.com/problems/two-sum/description/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        std::unordered_multimap<int, int> m; 
        for(int i=0; i<n; i++) m.insert({nums[i], i});

        std::sort(nums.begin(), nums.end());
        int i = 0, j = n-1;
        while(i < j) {
            int sum = nums[i] + nums[j];
            if(sum == target) {
                ans.push_back(m.find(nums[i])->second);
                m.erase(m.find(nums[i]));
                ans.push_back(m.find(nums[j])->second);
                break;
            }
            else if(sum > target) j--;
            else i++;
        }
        return ans;
    }
};