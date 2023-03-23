// https://leetcode.com/problems/sort-array-by-increasing-frequency/description/
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // TC is calculated excluding the given input i.e O(N)
        vector<int> ans;

        std::unordered_map<int, int> Hash; // O(1)
        for(auto &it : nums) Hash[it]++;

        std::priority_queue<std::pair<int, int>> minHeap; // O(LogN)
        for(auto &it : Hash) minHeap.push({it.second * -1, it.first}); // O(1) * O(LogN)

        while(!minHeap.empty()) { // O(LogN)
            int ele = minHeap.top().second;
            int freq = minHeap.top().first * -1;
            minHeap.pop();
            while(freq--) ans.push_back(ele); // O(LogN * freq)
        }
        return ans; // (O(1)*O(LogN)) + (O(LogN)*(freq)) = O(LogN * freq)
    }
};