// https://leetcode.com/problems/two-sum/description/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        std::unordered_multimap<int, int> m; 
        for(int i=0; i<n; i++) m.insert({nums[i], i});

        std::sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            int x = target - nums[i];
            if(std::binary_search(nums.begin()+i,nums.end(), x)) {
                ans.push_back(m.find(nums[i])->second);
                m.erase(m.find(nums[i]));
                ans.push_back(m.find(x)->second);
                break;
            } 
        }
        return ans;
    }
};