// 1 2 3 4 5
// =>
//5 4 3 2 1
//using loop O(N^2) and & space O(1) Bcz of no stack involve
//using recursion O(N) & space O(N)
#include<bits/stdc++.h>

using namespace std;

void rec(vector<int> &arr, int i, int j, int n)
{
    //baseCase
    if(j == n) return;



    cout<<i<<" "<<j<<"\n";
    for(auto it : arr) cout<<it<<" ";
    cout<<"\n";


    //recursiveCase
    rec(arr, i-1 , j+1, n);//tis is stack build & destroy once...then execute rest n thimes
    if(i >= j) return; //then...just return don't do anything stupid
    swap(arr[i], arr[j]);



    cout<<"\n";
    cout<<i<<" "<<j<<"\n";
    for(auto it : arr) cout<<it<<" ";
    cout<<"\n";
}
int main()
{
    int n=5;
    vector<int> arr = {1, 2, 3, 4, 5};
    rec(arr, n-1, 0, n);

    cout<<"\n\nin main\n";
    for(auto it : arr) cout<<it<<" ";
    return 0;
}