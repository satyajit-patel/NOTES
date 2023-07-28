// https://leetcode.com/problems/two-sum/description/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_multiset<int> st;
        for(auto &it : nums) st.insert(it);
        for(int i=0; i<nums.size(); i++) {
            auto it = st.find(nums[i]);
            st.erase(it);
            int x = target - nums[i];
            if(st.count(x)) {
                ans.push_back(i);
                break;
            }
            st.insert(nums[i]);
        }
        int ind = ans[0];
        for(int i=0; i<nums.size(); i++) {
            if(i != ind) {
                if(nums[i] + nums[ind] == target) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};