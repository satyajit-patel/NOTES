// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
class Solution {
public:
    long long minCost(long long arr[], long long n) {
        std::priority_queue<long long> minHeap;
        for(long long i=0; i<n; i++) minHeap.push(arr[i] * -1);
        long long totCost = 0;
        while(minHeap.size() != 1) {
            long long rope1 = minHeap.top() * -1;
            minHeap.pop();
            long long rope2 = minHeap.top() * -1;
            minHeap.pop();
            long long newRope = rope1 + rope2;
            totCost += newRope;
            minHeap.push(newRope * -1);
        }
        return totCost;
    }
};