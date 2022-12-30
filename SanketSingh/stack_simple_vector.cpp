#include<bits/stdc++.h>

using namespace std;

class Stack
{
public:

    vector<int> v;

    void push(int data)
    {
        v.push_back(data);
    }
    void pop()
    {
        if(v.empty())
            return;
        v.pop_back();
    }
    int top()
    {
        if(v.empty())
            return -1;
        return v.back();
    }
    int size()
    {
        return v.size();
    }
    bool empty()
    {
        return v.empty();
    }
};
int main()
{
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    for (int i = 10; i <= 15; i++)
    {
        s.push(i);
    }
    
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    

    return 0;
}