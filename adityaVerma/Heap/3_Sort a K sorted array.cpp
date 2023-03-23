// https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    vector<int> nearlySorted(int arr[], int num, int K){
        std::vector<int> ans;
        std::priority_queue<int> minHeap;
        for(int i=0; i<num; i++) { // N
            minHeap.push(arr[i] * -1); // Log(K)
            if(minHeap.size() > K) {
                int smallEle = minHeap.top() * -1;
                minHeap.pop();
                ans.push_back(smallEle);
            }
        }
        while(!minHeap.empty()) { // K
            int smallEle = minHeap.top() * -1;
            minHeap.pop();
            ans.push_back(smallEle);
        }
        // (N * Log(K)) + K = O(NLog(K))
        return ans;
    }
};