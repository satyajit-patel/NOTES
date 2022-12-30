#include<bits/stdc++.h>

using namespace std;
int main()
{
    vector<int> v;
    for(int i = 1; i <= 3; i++)
    {
        v.push_back(i);
    }
    

    cout<<"its permutations are:\n";
    do
    {
        for(auto it=v.begin(); it != v.end(); it++)
            cout<<(*it)<<" ";
        cout<<"\n";
    } 
    while (next_permutation(v.begin(), v.end()));
    

    return 0;
}