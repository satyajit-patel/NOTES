#include<iostream>

using namespace std;

int dp[1000] = {0};
int fibo(int n)
{
    //baseCase
    if(n <= 1) return n;
    if(dp[n] != 0) return dp[n];


    //recursiveCase
    return dp[n] = fibo(n-1) + fibo(n-2);
}
int main()
{
    cout<<fibo(8);
    return 0;
}