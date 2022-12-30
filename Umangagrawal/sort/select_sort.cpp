#include<bits/stdc++.h>

using namespace std;
void solve(vector<int> v, int size)
{
    int count=0;
    for (int i = 0; i < size-1; i++)
    {
        int min=i;
        for (int j = i+1; j < size; j++)
        {
            if(v[j] < v[min]){
                min=j;
                count++;
            }
        }
        swap(v[i], v[min]);
    }
    
    for(auto i : v)
        cout<<i<<" ";
    cout<<"\n"<<count;
}
int main()
{
    vector<int> v;
    cout<<"enter size\n";
    int size;cin>>size;
    cout<<"enter elements\n";
    for (int i = 0; i < size; i++)
    {
        int n;cin>>n;
        v.push_back(n);
    }
    solve(v, size);
    return 0;
}