#include<iostream>
using namespace std;
void swapp(int *a, int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void sort(int a[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        bool swapped= false;
        for (int j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                swapp(&a[j], &a[j+1]);
                swapped= true;
            }
        }
        if(swapped == false)
            break;
    }
    

}
void print(int a[], int n)
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
    print(a,size);

    return 0;
}