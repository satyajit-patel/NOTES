#include<iostream>
using namespace std;
void sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key=a[i],j=i-1;
        while (j>=0 && a[j] > key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;   
    }
}
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<"\t";
    }
    
}
int main()
{
    int size;
    cout<<"size\n";
    cin>>size;
    int a[size];
    cout<<"enter numbers\n";
    for (int i = 0; i < size; i++)
    {
        cin>>a[i];
    }

    sort(a,size);
    cout<<"sorted:\n";
    display(a,size);

    return 0;   
}