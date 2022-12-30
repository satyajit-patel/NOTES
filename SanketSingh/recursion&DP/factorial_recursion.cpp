#include<iostream>

using namespace std;

int fact(int n)
{
    /*
    if(n == 0)//base condition
        return 1;
    //recursive condition
    return n*fact(n-1);
    */

    return (n==0)? 1 : n*fact(n-1);
}
int main()
{
    int f=fact(5);
    cout<<f;
    return 0;
}