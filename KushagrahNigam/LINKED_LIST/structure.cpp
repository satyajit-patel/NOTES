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

void pushFront(int val){
    Node *A = new Node(val);

    A->next = head;
    head = A;
}
void pushBack(int val){
    Node *P = head;
    while(P->next != NULL){
        P = P->next;
    }

    Node *A = new Node(val);
    P->next = A;
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
    return 0;
}