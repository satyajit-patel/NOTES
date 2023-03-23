// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
class Solution {
public:
    int kthSmallest(int arr[], int l, int r, int k) {

	// identification : -
	// should be given K and must be asked for any smallest/largest
	// if asked smallest/lowest/closest -> then make (max heap)
	// if asked largest/greatest/top -> then make (min heap)

        std::priority_queue<int> maxHeap;
        for(int i=l; i<=r; i++) {
            maxHeap.push(arr[i]);
            if(maxHeap.size() > k) maxHeap.pop();
        }
	// O(N Log(k))
        return maxHeap.top();
    }
};