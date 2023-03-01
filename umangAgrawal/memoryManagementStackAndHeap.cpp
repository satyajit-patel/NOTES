#include <bits/stdc++.h>

using namespace std;
struct temp {
    int val;

    //constructor(get called when object is created)
    temp() {
        cout<<"Constructor Called\n";
        val = 10;
    }

    //destructor(get called when structure is about to destroy)
    ~temp() {
        cout<<"Destructor Called\n";
    }
};
void allocationInStack() {
    temp t1;
    t1.val = 20;
    cout<<t1.val<<endl;
}
void allocationInHeap() {
    temp *t1 = new temp;
    cout<<t1->val<<endl;

    //we have to delete the space mamually here, otherwise Destructor would'nt get called
    delete t1;
}
void arrayInStack() {
    temp arr[2]; // 2 times object will be get created(i.e 2 times Constuctor will get called)
}
void arrayInHeap() {
    temp *arr = new temp[2];
}
void arrayInHeapWithManualDeletion() {
    temp *arr = new temp[2];
    delete arr; //this will delete the only ist index(so 1 time only Destructor will get called)
}
void arrayInHeapWithManualDeletion2() {
    temp *arr = new temp[3];
    delete []arr;
}
int main() {
    allocationInStack();
    allocationInHeap();
    cout<<"--------------------------------------\n";
    arrayInStack();
    cout<<"--------------------------------------\n";
    arrayInHeap();
    cout<<"--------------------------------------\n";
    arrayInHeapWithManualDeletion();
    cout<<"--------------------------------------\n";
    arrayInHeapWithManualDeletion2();
    return 0;
}

free() is c funcntion.. it only frees memory
delete is c++ keyword.. it frees memory & calls the destroctor either 