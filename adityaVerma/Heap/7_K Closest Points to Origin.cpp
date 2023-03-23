// https://leetcode.com/problems/k-closest-points-to-origin/description/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<std::pair<int, std::vector<int>>> maxHeap;
        for(auto &row : points) {
            std::vector<int> temp(row.begin(), row.end());
            int x = temp[0];
            int y = temp[1];
            int dist = std::pow(x, 2) + std::pow(y, 2);
            
            maxHeap.push({dist, temp});
            if(maxHeap.size() > k) maxHeap.pop();
        }
        vector<vector<int>> ans;
        while(!maxHeap.empty()) {
            std::vector<int> temp = maxHeap.top().second;
            maxHeap.pop();
            ans.push_back(temp);
        }
        return ans;
    }
};