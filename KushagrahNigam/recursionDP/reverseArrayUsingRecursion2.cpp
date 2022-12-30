// 1 2 3 4 5
// =>
//5 4 3 2 1
//using loop O(N^2) and & space O(1) Bcz of no stack involve
//using recursion O(N) & space O(N)
#include<bits/stdc++.h>

using namespace std;
int i, n; //making global for easier use
void rec(vector<int> &arr, int j)
{
    //baseCase
    if(j == n) return;



    cout<<i<<" "<<j<<"\n";
    for(auto it : arr) cout<<it<<" ";
    cout<<"\n";


    //recursiveCase
    rec(arr, j+1);
    if(i >= j) return;
    swap(arr[i], arr[j]);
    i++;



    cout<<"\n";
    cout<<i<<" "<<j<<"\n";
    for(auto it : arr) cout<<it<<" ";
    cout<<"\n";
}
int main()
{
    n=5, i=0;
    vector<int> arr = {1, 2, 3, 4, 5};
    rec(arr, 0);

    cout<<"\n\nin main\n";
    for(auto it : arr) cout<<it<<" ";
    return 0;
}