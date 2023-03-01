// https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int N = nums.size();
        std::set<std::pair<int, int>> st;
        // 2 pointer approach
        std::sort(nums.begin(), nums.end());
        int i = 0, j = 1;
        while(i < N && j < N) {
            int diff = nums[j] - nums[i];
            if(diff == k) {
                st.insert({nums[i], nums[j]});
                i++;
                j++;
            }
            else if(diff > k) i++;
            else j++;
            if(i == j) j++;
        }
        return st.size();
    }
};