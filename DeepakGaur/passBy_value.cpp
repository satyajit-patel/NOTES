#include<bits/stdc++.h>

using namespace std;
void solve(int *p, int n)
{
    *p += 10;
    n += 90;

    cout<<"inside function actual initially 10...now "<<*p;
    cout<<"\n";
    cout<<"inside function normal initially 10...now "<<n;
    cout<<"\n";

}
int main()
{
    int actual=10;
    int normal=10;
    int *p;
    p=&actual;

    *p= *p *= 2;

    cout<<"before calling actual initially 10...now "<<actual;
    cout<<"\n";
    cout<<"before calling normal initially 10...now "<<normal;
    cout<<"\n";

    solve(&actual ,normal);

    cout<<"after calling actual initially 10...now "<<actual;
    cout<<"\n";
    cout<<"after calling normal initially 10...now "<<normal;
    cout<<"\n";
    return 0;
}