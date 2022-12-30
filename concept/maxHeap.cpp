#include<bits/stdc++.h>

using namespace std;
int main()
{
    priority_queue<int> pq; //maxHeap
    pq.push(5);
    pq.push(2);
    pq.push(20);
    pq.push(10);
    pq.push(-3);

    vector<int> vec;
    for(int i=10; i != 12; i++) vec.push_back(i);

    for(auto it : vec) pq.push(it);


    cout<<pq.top()<<"\n";
    pq.pop();
    cout<<pq.top()<<"\n";
    return 0;
}