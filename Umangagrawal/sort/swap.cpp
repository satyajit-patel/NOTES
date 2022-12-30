#include<iostream>
using namespace std;
void swap(int *a, int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int main()
{
    int a=10,b=20;
    int arr[2]={100,200};
    swap(arr[0], arr[1]);
    //swap(&a,&b);
    cout<<arr[0]<<"\t"<<arr[1];
    return 0;
}