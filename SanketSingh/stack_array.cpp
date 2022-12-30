#include<bits/stdc++.h>

using namespace std;

class Product
{
    int arr[10];
    int size;

    public:
        Product() //constructor
        {
            size=0; //when object is created, constructor is called automatically
                    //so intitially size will be zero
        }

        void push(int item)
        {
            if(size == 100)
                return; //overflow
            arr[size++]=item;
        }
        void pop()
        {
            if(!size)
                return; //underflow
            size--;    
        }
        int top()
        {
            if(!size)
                return -1;//exception
            return arr[size -1];
        }
        int capacity()
        {
            return size;
        }
        bool empty()
        {
            return size==0;
        }
        void display()
        {
            for (int i = 0; i < size; i++)
            {
                cout<<arr[i]<<" ";
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
    cout<<"\n"<<p1.capacity();

    p1.pop();
    p1.pop();
    p1.pop();
    p1.pop();

    cout<<"\n\n";
    p1.display();
    cout<<"\n"<<p1.empty();
    cout<<"\n"<<p1.top();
    cout<<"\n"<<p1.capacity();


    return 0;
}