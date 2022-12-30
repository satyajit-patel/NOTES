//first in first out
#include<bits/stdc++.h>

using namespace std;
class queue2
{
private:
    stack<int> stack_in;
    stack<int> stack_out;
public:
    void push(int num) //O(1)
    {
        stack_in.push(num);
    }
    void pop() //O(N)
    {
        if(stack_out.empty()){
            while (stack_in.size()) //while stack_in.size != 0
            {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }

        if(stack_out.size())
            stack_out.pop();
        else
            cout<<"queue empty\n";
    }
    int front()
    {
        if(stack_out.empty())
            return -1;
        return stack_out.top();
    }

    queue2(){}
    queue2(vector<int> arr)
    {
        for(auto i : arr)
            stack_in.push(i);
    }
};
int main()
{
    vector<int> arr{1,2,3,4,5};
    queue2 q(arr);

    q.pop();
    cout<<q.front();
    return 0;
}