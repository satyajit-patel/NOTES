// https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> Hash;
        for(auto &it : nums) Hash[it]++; // O(1) as it is unordered map which is nearly O(1) 

        std::priority_queue<std::pair<int, int>> minHeap;
        for(auto &it : Hash) {
            minHeap.push({it.second * -1, it.first}); // O(Log(K))
            if(minHeap.size() > k) minHeap.pop();
        }

        std::vector<int> ans;
        while(!minHeap.empty()) { // K
            int ele = minHeap.top().second;
            minHeap.pop();
            ans.push_back(ele);
        }
        return ans; // (O(1) * Log(K)) + K = O(Log(K))
    }
};