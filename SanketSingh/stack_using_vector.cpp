#include<bits/stdc++.h>

using namespace std;

class Product
{
    vector<int> v;

    public:
        Product(){}
        Product(vector<int> &inp)
        {
            v= inp;
        }

        void pop()
        {
            if(v.empty())
                return;
            v.pop_back();
        }
        void push(int item)
        {
            v.push_back(item);
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
        void display()
        {
            for (int i = 0; i < v.size(); i++)
            {
                cout<<v[i]<<" ";
            }
            
        }
};

int main()
{
    Product p1;

    p1.push(1);
    p1.push(2);
    p1.push(3);
    p1.push(4);

    p1.display();
    cout<<"\n"<<p1.empty();
    cout<<"\n"<<p1.top();
    cout<<"\n"<<p1.size();

    p1.pop();
    p1.pop();
    p1.pop();
    p1.pop();

    cout<<"\n\n";
    p1.display();
    cout<<"\n"<<p1.empty();
    cout<<"\n"<<p1.top();
    cout<<"\n"<<p1.size();

    return 0;
}