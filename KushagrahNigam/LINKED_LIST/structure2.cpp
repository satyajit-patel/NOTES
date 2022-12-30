#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

Node *head = new Node(1);
Node *tail = head;

void pushFront(int val){
    Node *A = new Node(val);

    A->next = head;
    head = A;
}
void pushBack(int val){
    //O(1)
    Node *A = new Node(val);

    tail->next = A;
    tail = tail->next;
}
void pushAtPosition(int index, int val){
    int i = 1;
    Node *P = head;
    while(i != (index-1)){
        P = P->next;
        i++;
    }

    Node *A = new Node(val);
    A->next = P->next;
    P->next = A;
}

void traverse(){
    Node *P = head;
    while(P != NULL){
        cout<<P->data<<" ";
        P = P->next;
    }
    cout<<"\n";
}




//deletion
void popFront(){
    head = head->next;
}
void popBack(){
    //O(N)
    //we need to travel till prev of target element
    Node *P = head;
    while(P->next->next != NULL){
        P = P->next;
    }

    P->next = NULL;
}
void popAtPosition(int index){
    int i = 1;
    Node *P = head;
    while(i != (index-1)){
        P = P->next;
        i++;
    }

    P->next = P->next->next;
}
void popTheElement(int val){
    Node *P = head;
    while(P->next->data != val){
        P = P->next;
    }

    P->next = P->next->next;
}


int main()
{
    //initially head contains 1
    pushFront(0);
    pushBack(2);
    pushBack(3);
    pushBack(4);
    pushBack(5);

    traverse();

    pushAtPosition(4, 10);

    traverse();


    pushFront(-1);
    pushBack(99);
    pushBack(100);

    traverse(); //-1 -> 0 -> 1 -> 2 -> 10 -> 3 -> 4 -> 5-> 100


    popAtPosition(5);
    traverse();
    popFront();
    popBack();
    traverse();
    popTheElement(99);
    traverse();
    return 0;
}