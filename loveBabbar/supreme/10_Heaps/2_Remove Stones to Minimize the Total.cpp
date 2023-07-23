// https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        std::priority_queue<int> maxHeap; 
        for(auto &it : piles) maxHeap.push(it); // O(N)
        while(k--) { // O(K)
            int ele = maxHeap.top();
            maxHeap.pop();
            ele = std::ceil((ele*1.0)/2);
            maxHeap.push(ele); // O(logN
        }
        int minStone = 0;
        while(!maxHeap.empty()) { // O(N)
            int ele = maxHeap.top();
            maxHeap.pop();
            minStone += ele;
        }
        return minStone;
	// O(N + KlogN)
    }
};