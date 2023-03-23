// https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    std::priority_queue<int> minHeap;
	    for(int i=0; i<n; i++) { // O(N)
	        minHeap.push(arr[i] * -1); // O(Log(k))
	        if(minHeap.size() > k) minHeap.pop();
	    }
	    std::vector<int> ans;
	    while(!minHeap.empty()) {
	        ans.push_back(minHeap.top() * -1);
	        minHeap.pop();
	    }
	    std::reverse(ans.begin(), ans.end()); // O(N);
	    // (N * Log(K)) + K + N = O(NLog(k))
	    return ans;
	}

};