#include<bits/stdc++.h>

using namespace std;
class Node
{
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int d){
            data= d;
            next= NULL;
            prev= NULL;
        }
};

class LinkedList
{
    public:
        Node *head;
        Node *tail;
        int size;

        LinkedList()
        {
            head=NULL;
            tail=NULL;
        }

        void push_front(int d)
        {
            Node *new_node = new Node(d);

            if(!head){
                tail= new_node;
                head= new_node;
            }
            else{
                new_node->next = head;
                head->prev = new_node;

                head = new_node;
            }
            size++;
        }
        void push_back(int d)
        {
            Node *new_node = new Node(d);

            if(!tail){
                head= new_node;
                tail= new_node;
            }
            else{
                tail->next = new_node;
                new_node->prev = tail;

                tail = new_node;
            }
            size++;
        }
        Node* insert(Node *cur, int d)
        {
            Node *new_node = new Node(d);

            new_node->next = cur->next;
            new_node->prev = cur;

            cur->next = new_node;
            if(new_node->next){
                new_node->next->prev = new_node;
            }
            else{
                tail = new_node;
            }
            size++;

            return new_node;
        }

        void pop_back()
        {
            if(!tail)
                return;
            if(!(tail->prev)){
                delete head; //or delete tail;
                head= tail= NULL;
            }
            else{
                Node *new_tail = tail->prev;
                new_tail->next = NULL;

                delete tail;
                tail = new_tail;
            }
            size--;
        }
        void pop_front()
        {
            if(!head)
                return;
            if(!(head->next)){
                delete head;
                head= tail= NULL;
            }
            else{
                Node *new_head = head->next;
                new_head->prev = NULL;

                delete head;
                head= new_head;
            }
            size--;
        }
        void pop(Node *cur)
        {
            if(size == 1){
                delete cur;
                head= tail= NULL;
            }
            if(cur->prev){
                cur->prev->next = cur->next;
            }
            if(cur->next){
                cur->next->prev = cur->prev;
            }
            if(cur == head){
                head = cur->next;
            }
            if(cur == tail){
                tail = cur->prev;
            }

            delete cur;
            size--;
        }
        void print()
        {
            Node *cur = head;
            while(cur)
            {
                cout<<cur->data<<" ";
                cur = cur->next;
            }
            cout<<endl;
        }
};
int main()
{
    LinkedList p1;

    for (int i = 1; i <= 5; i++)
    {
        p1.push_back(i);
    }
    p1.print();

    auto eleven = p1.insert(p1.head, 11);
    p1.print();

    p1.pop(eleven);
    p1.print();
    
    p1.pop(p1.tail);
    p1.print();

    return 0;
}