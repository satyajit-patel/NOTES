#include<iostream>

using namespace std;

int fibo(int n)
{
    //baseCase
    if(n <= 1) return n;


    //recursiveCase
    return fibo(n-1) + fibo(n-2);
}
int main()
{
    cout<<fibo(8);
    return 0;
}