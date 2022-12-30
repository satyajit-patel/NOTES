#include<iostream>

using namespace std;

bool subsetSum(int arr[], int n, int sum)
{
    //baseCase
    if(sum == 0) return true; //Bcz empty is also a sebset
    if(n == 0 && sum > 0) return false;


    //recursiveCase
    if(arr[n-1] <= sum){
        //takeIt
        int x = subsetSum(arr, n-1, sum-arr[n-1]);

        //!takeIt
        int y = subsetSum(arr, n-1, sum);


        return (x || y);
    }
    else
    {
        //discardIt
        return subsetSum(arr, n-1, sum);
    }
}
int main()
{
    int n=3;
    int sum=5;
    int arr[n]={2, 3, 5};

    cout<<subsetSum(arr, n, sum);
    return 0;
}