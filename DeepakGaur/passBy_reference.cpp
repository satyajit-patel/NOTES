#include<bits/stdc++.h>

using namespace std;
void solve(int &loki_2)//calling by reference
{
    loki_2 += 10;
}
int main()
{
    int loki= 10;

    int &loki_1= loki; //just another variant of loki..but they are both same
    int &loki_100= loki;

    cout<<"\nbefore calling "<<loki<<" "<<loki_1;
    solve(loki_100);
    cout<<"\nafter calling by reference "<<loki<<" "<<loki_1;
    return 0;
}