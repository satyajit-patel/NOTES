/ https://leetcode.com/problems/find-k-closest-elements/description/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        std::priority_queue<std::pair<int, int>> maxHeap;
        for(int i=0; i<arr.size(); i++) { // N
            int key = std::abs(arr[i] - x);
            // if(key == 0) continue; // exclude x
            maxHeap.push({key, arr[i]}); // Log(k)
            if(maxHeap.size() > k) maxHeap.pop();
        }
        std::vector<int> ans;
        while(!maxHeap.empty()) { // K
            int ele = maxHeap.top().second;
            maxHeap.pop();
            ans.push_back(ele);
        }
        std::sort(ans.begin(), ans.end()); // NLog(N)
        return ans; // (N*Log(k)) + K + NLog(N) = O(NLog(N))
    }
};