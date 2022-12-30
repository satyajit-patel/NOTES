#include<bits/stdc++.h>

using namespace std;

class Node
{
    private:
        int *arr, front, sz, rear,cap; 

    public :

        Node(int cap)
        {
            arr = new int[cap];
            front = 0, rear = -1, sz= 0, this->cap = cap;
        }

        void push(int num)
        {
            if(sz == cap){
                cout<<"\n overflow\n";
                return;
            }
            rear = (rear+1) % cap;
            arr[rear] = num;

            sz ++; 
        }
    
        void pop()
        {
            if(!sz){
                cout<<"underflow";
                return;
            }
            front=front+1 % cap;

            sz--;
        }
        
        int back()
        {
            if(sz)
                return arr[rear];
            cout<<"\nunderflow\n";
            return -1;
        }
        int front_value()
        {
            if(sz)
                return arr[front];
            cout<<"\nunderflow\n";
            return -1;
        }
        bool empty()
        {
            return (sz == 0);
        }
        void clear()
        {
            while(sz)
                pop();
        }
        int size()
        {
            return sz;
        }
        void print()
        {
            while (!empty())
            {
                cout<<front_value()<<" ";
                pop();
            }
            cout<<endl;
        }
        
};
int main()
{
    Node p1(5);
    p1.push(10);
    p1.push(20);
    p1.push(30);

    

    cout<<p1.front_value()<<"\n";
    cout<<p1.back()<<"\n";

    p1.print();
    //p1.clear();
    cout<<p1.back();

    return 0;
}