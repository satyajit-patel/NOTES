// https://leetcode.com/problems/k-diff-pairs-in-an-array/submissions/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        std::map<int, int> map;
        for(auto &it : nums) map[it]++;
        int ans = 0;
        for(auto it : map) {
            // a - b = k
            // a + k = b so if b exist in forward i.e we found a pair 
            if((!k && it.second > 1) || (k && map.count(it.first + k))) ans++;
        }
        return ans;
    }
};