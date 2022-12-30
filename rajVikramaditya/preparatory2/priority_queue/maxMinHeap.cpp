#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 9;
    vector<int> arr = {2,5,1,3,7,2,4,9,7};
    
    priority_queue<int> maxHeap;
    for(auto &it:arr) maxHeap.push(it);
    cout<<maxHeap.top()<<"\n";
    
    priority_queue<int> minHeap;
    for(auto &it:arr) minHeap.push(it * -1);
    cout<<minHeap.top() * -1<<"\n";

    return 0;
}