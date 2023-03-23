// https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> ans;
        std::unordered_set<int> st(nums.begin(), nums.end()); // O(1)
        std::multimap<int, int, greater<int>> Hash;
        for(auto &it : st) { 
            int occurrence = std::count(nums.begin(), nums.end(), it); // N
            Hash.insert({occurrence, it}); // LogN
        }
        for(auto &it : Hash) { // N
            if(k == 0) break;
            ans.push_back(it.second);
            k -= 1;
        }
        return ans; // (O(1) * N + Log(N)) + K = O(N)

	// std::vector<int> ans;
        // std::unordered_set<int> st(nums.begin(), nums.end());
        // std::multimap<int, int> Hash;
        // for(auto &it : st) {
        //     int occurrence = std::count(nums.begin(), nums.end(), it);
        //     Hash.insert({occurrence, it});
        // }
        // for(auto it=Hash.rbegin(); it != Hash.rend(); it++) {
        //     if(k == 0) break;
        //     ans.push_back(it->second);
        //     k -= 1;
        // }
        // return ans;
    }
};