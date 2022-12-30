#include<bits/stdc++.h>
using namespace std;

void merge(int i, int mid, int j, int arr[])
{
    int N1= mid - i + 1;
    int N2= j - mid;
    int A1[N1], A2[N2];

    for (int k= 0; k < N1; k++)
    {
        A1[k]= arr[i + k];
    }
    for (int k = 0; k < N2; k++)
    {
        A2[k]= arr[( mid + 1) + k];
    }
    //two pointer concept
    int x=0, y=0;
    int z= i;
    while (x < N1 and y < N2)
    {
        if(A1[x] <= A2[y])
        {
             arr[z++]= A1[x++];     
        }
        else
        {
             arr[z++]= A2[y++];
        }
    }
    //if anything left in any array then put it directly
    while (x < N1)
    {
         arr[z++]= A1[x++];
    }
    while (y < N2)
    {
         arr[z++]= A2[y++];
    }
    
    
    
    return;
}

void divide(int start, int end, int arr[])
{
    
    int size= end - start +1;
    if(size == 1)
    {
        return;
    }

    //int mid= (start + end) >> 1;
    int mid= start + (end - start) / 2;
    divide(start, mid, arr);
    divide(mid + 1, end, arr);

    merge(start, mid, end, arr);
    
}
int main()
{
    int N=8;
    int arr[]={8,7,6,5,4,3,2,1};
    divide(0, 7, arr);

    cout<<"sorted\n";
    for (int i = 0; i < N; i++)
    {
        cout<<arr[i]<<"\t";
    }


    return 0;
}