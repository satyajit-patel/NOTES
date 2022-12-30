//last in first out
#include<bits/stdc++.h>

using namespace std;
class stackq
{
private:
    queue<int> q;
public:
    void push(int num)
    {
        q.push(num);
    }
    void pop()
    {
        int n=q.size();
        n--; //except last element

        while (n--)
        {
            q.push(q.front()); //basically we will get the same elements
            q.pop();
        }

        q.pop();
        
    }
    int top()
    {
        if(q.empty())
            return -1;
        return q.back();
    }

    stackq(){}
    stackq(vector<int> arr)
    {
        for(auto i : arr)
            q.push(i);
    }
};
int main()
{
    vector<int> arr{1,2,3,4,5};
    stackq s(arr);
    s.pop();
    cout<<s.top();
    return 0;
}