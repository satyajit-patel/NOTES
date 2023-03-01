#include<bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> weighted_v;
vector<int> DP;

int get_this_is_my_path(int i)
{
    if(DP[i] != -1)
        return DP[i];
    DP[i]=0;//it no neighbour exist then return ans as 0

    for(auto nb : weighted_v[i])//traverse its neighbours...pair<int, int> nb or auto
    {
        int cur=nb.first, w=nb.second;
        DP[i]=max(DP[i], get_this_is_my_path(cur) + w);
    }
    return DP[i];
}
int main()
{
    cout<<"enter no of nodes and edges\n";
    int n,m; cin>>n>>m;

    weighted_v.resize(n+1);
    DP.assign(n+1,-1);

    while (m--)
    {
        int i,j,w; cin>>i>>j>>w;//w is weight

        //connect the arrow with weight
        weighted_v[i].push_back({j,w});
    }
    int ans=0;
    for(int i=1; i<= n; i++){
        ans=max(ans, get_this_is_my_path(i));
    }
    cout<<ans;
    return 0;
}