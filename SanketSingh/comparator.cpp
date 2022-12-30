//sort according to area of rectangle
#include<bits/stdc++.h>

using namespace std;

bool my_comparator(pair<int, int> p1, pair<int, int> p2)
{
    if(p1.first * p1.second < p2.first * p2.second)
        return true;
    else
        return false;
}

int main()
{
    vector<pair<int, int> > v{ {2,3}, {1,20}, {5,3} };

    cout<<"normal sort\n";
    sort(v.begin(), v.end());
    for(auto it=v.begin(); it != v.end(); it++)
        cout<<"{"<<(*it).first<<","<<(*it).second<<"}"<<" ";

    cout<<"\nsorted according to area in increasing order\n";
    sort(v.begin(), v.end(), my_comparator);//comparator is a boolean no need to pass argu
    for(auto it=v.begin(); it != v.end(); it++)
        cout<<"{"<<(*it).first<<","<<(*it).second<<"}"<<" ";


    return 0;
}