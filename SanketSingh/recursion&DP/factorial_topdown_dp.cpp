#include<bits/stdc++.h>

using namespace std;

vector<int> v(101, -1);
int memoization(int n)
{
    //in factorial no need of DP but still for practice sake
    if(n == 0)
        return 1;
    if(v[n] != -1)
        return v[n];
    else{
        return v[n]= n*memoization(n-1);
    }
}
int main()
{
    cout<<memoization(5);
    return 0;
}