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


void segregate()
{
    //take 2dummy head
    Node *oddHead = new Node(0);
    Node *evevHead = new Node(0);

    Node *P = head;
    Node *X = oddHead;
    Node *Y = evevHead;

    //1 2 3 4 6 8 5 7
    while(P != NULL)
    {
        if(P->data %2 == 1)
        {
            X->next = P;
            X = X->next;
            //cout<<X->data<<"\n";
        }
        else{
            Y->next = P;
            Y = Y->next;
        }

        P = P->next;
    }
    //odd:      0 1 3 5
    //even:     0 2 4 6

    X->next = evevHead->next;
    Y->next = NULL;
    head = oddHead->next;
}


int main()
{

    pushBack(2);
    pushBack(3);
    pushBack(4);
    pushBack(6);
    pushBack(8);
    pushBack(5);
    pushBack(7);
    //1 2 3 4 6 8 5 7

    traverse();
    segregate();
    traverse();
    return 0;
}