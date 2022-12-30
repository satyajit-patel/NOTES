#include<bits/stdc++.h>

using namespace std;

vector<int> v(101, -1);
int fibo(int n)
{
    if(n <= 1)//base condition
        return n;
    if(v[n] != -1)//i.e already calculated
        return v[n];
    else//recursive condition
        return v[n]= fibo(n-1) + fibo(n-2);
}
int main()
{
    //for(auto it : v)
    //   cout<<it<<" ";

    cout<<fibo(9);
    return 0;
}