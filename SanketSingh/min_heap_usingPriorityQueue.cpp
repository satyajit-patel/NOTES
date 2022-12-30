#include<bits/stdc++.h>

using namespace std;
int main()
{
    vector<int> arr{6,5,4,3,2,1};

    //priority_queue<int> q(arr.begin(), arr.end()); //max heap
    priority_queue<int,vector<int>, greater<int>> q(arr.begin(), arr.end()); //min heap

    cout<<q.top()<<"\n";
    while (!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    return 0;
}