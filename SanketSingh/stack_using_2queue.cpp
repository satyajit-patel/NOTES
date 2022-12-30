//last in fast out
#include<bits/stdc++.h>

using namespace std;
class stackq
{
private:
    queue<int> main;
    queue<int> aux;

public:
    void push(int num) //just push in main
    {
        main.push(num);
    }
    void pop() //transfer all main to aux except last element, delete main, then transfer back to main
    {
        int n=main.size();
        n--;

        while(n--) //i.e while n != 0
        {
            aux.push(main.front());
            main.pop();
        }
    
        main.pop();

        n=aux.size();
        while(n--)
        {
            main.push(aux.front());
            aux.pop();
        }
        cout<<"phase3\n";
    }
    int top()
    {
        if(main.empty())
            return -1;
        return main.back();
    }

    stackq(){}
    stackq(vector<int> arr)
    {
        for(auto i : arr)
            main.push(i);
    }
};
int main()
{
    vector<int> arr{1,2,3,4,5,6};
    stackq s(arr);

    cout<<s.top()<<"\n";
    s.pop();
    cout<<s.top()<<"\n";
    s.push(100);
    cout<<s.top()<<"\n";
    return 0;
}
