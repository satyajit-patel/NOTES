#include<bits/stdc++.h>

using namespace std;
int fibo(int n)
{
    return (n <= 1)? n : fibo(n-1)+fibo(n-2);
}
int main()
{
    int n;
    cout<<"enter number\n";
    cin>>n;

    int fib=fibo(n);
    cout<<fib<<"\n";

    return 0;
}