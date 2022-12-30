#include<iostream>
using namespace std;
void exchange(int *a, int *b)
{
    int t;

    t=*a;
    *a=*b;
    *b=t;
}
void print(int arr[], int count)
{
    for (int i = 0; i < count; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
void sort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min= i;
        for (int j= i+1; j < n; j++)
        {
            if(arr[j] < arr[min])
                min= j;
        }
        exchange(&arr[i], &arr[min]);
        print(arr, n);
    }
}
int main()
{
    int count;
    //cout<<"size\n";
    cin>>count;
    int arr[count];
    //cout<<"enter numbers\n";
    for (int i = 0; i < count; i++)
    {
        cin>>arr[i];
    }
    sort(arr, count);
    return 0;
}
