#include<bits/stdc++.h>

using namespace std;
int main()
{
    pair<pair<int, int>, vector<pair<string, double> > > p3=
    make_pair(make_pair(2, 3), vector<pair<string, double>>
    {make_pair("hello", 0.1), make_pair("hi", 0.2)});

    //cout<<p3.first.first;
    cout<<p3.second[0].first;
    


    return 0;
}