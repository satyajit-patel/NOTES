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

void pushBack(int val){

    Node *P = head;
    while(P->next != NULL){
        P = P->next;
    }

    Node *A = new Node(val);
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


void rev(){
    Node *prev = NULL;
    Node *cur = head;
    Node *nxt = NULL;

    while(cur != NULL){

        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;

    }
    head = prev;
}


int main()
{

    pushBack(2);
    pushBack(3);
    pushBack(4);

    traverse();
    rev();
    traverse();
    return 0;
}