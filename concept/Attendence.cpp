#include<bits/stdc++.h>

using namespace std;
int main()
{
    cout<<"enter size and names\n";
    int n;cin>>n;
    pair<string, string> p[n];
    map<string, int> mpp;
    for(int i=0; i<n; i++){
        cin>>p[i].first>>p[i].second;
        mpp[p[i].first]++;
    }

    cout<<"\n";
    for(int i=0; i<n; i++){
        if(mpp[p[i].first] == 1){
            cout<<p[i].first<<"\n";
        }
        else{
            cout<<p[i].first<<" "<<p[i].second<<"\n";
        }
    }
    return 0;
}