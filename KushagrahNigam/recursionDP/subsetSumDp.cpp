#include<iostream>
#include<vector>

using namespace std;

vector<vector<bool>> dp(1000, vector<bool>(1000, 0));
bool subsetSum(int arr[], int n, int sum)
{
    //baseCase
    if(sum == 0) return true; //Bcz empty is also a sebset
    if(n == 0 && sum > 0) return false;
    if(dp[n][sum] != 0) return dp[n][sum];


    //recursiveCase
    if(arr[n-1] <= sum){
        //takeIt
        int x = subsetSum(arr, n-1, sum-arr[n-1]);

        //!takeIt
        int y = subsetSum(arr, n-1, sum);


        return dp[n][sum] = (x || y);
    }
    else
    {
        //discardIt
        return dp[n][sum] = subsetSum(arr, n-1, sum);
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