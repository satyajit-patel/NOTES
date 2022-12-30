#include<bits/stdc++.h>

using namespace std;
class Node
{
    public:
        int data;
        Node *next;

        Node(int d) : data(d), next(NULL){}  
};

class queue_list
{
    Node *front, *rear;
    int size;
public:

    queue_list() : front(NULL), rear(NULL), size(0){}

    void push(int d)
    {
        Node *new_node = new Node(d);

        if(!size)
            front = rear = new_node;
        else{
            rear->next = new_node;
            rear = new_node;
        } 
        size++;
    }
    void pop()
    {
        if(!size){
            cout<<"\nunderflow!\n";
            return;
        }
        if(size == 1){
            rear = NULL;
        }
        Node *temp = front->next;

        delete front;
        front = temp;

        size--;
    }
    int front_value()
    {
        if(size){
            return front->data;
        }
        cout<<"\nqueue emptty!\n";
        return size;
    }
    int capacity()
    {
        return size;
    }
    bool empty()
    {
        return (size == 0);
    }
    void clear()
    {
        while (size)
        {
            pop();
        }
        
    }
};

int main()
{
    queue_list p1;

    for (int i = 1; i <= 5; i++)
    {
        p1.push(i);
    }

    cout<<p1.front_value()<<"\n";
    cout<<p1.capacity()<<"\n";

    while (p1.capacity())
    {
        cout<<p1.front_value()<<" ";
        p1.pop();
    }
    cout<<endl;
    
    cout<<p1.front_value()<<"\n";
    cout<<p1.capacity()<<"\n";
    

    return 0;
}