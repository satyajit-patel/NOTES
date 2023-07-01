#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> v;

bool dfs_for_topo(int i, vector<int> &ans, vector<int> &visited)
{
    visited[i]=1;

    //iterates over neighbour
    for(int nb : v[i])
    {
        if(visited[nb] == 0)
        {
            bool exists = dfs_for_topo(nb, ans, visited);
            if(!exists)
                return false;
        }
        else if(visited[nb] == 1)
            return false; //i.e there is back_edge or cycle
    }
    visited[i]=2;//i.e no cycle
    ans.push_back(i);
    return true;
}

vector<int> topo_by_dfs()
{
    vector<int> visited(n+1,0), ans;
    bool possible=true;

    for (int i = 0; i <= n; i++)
    {
        if(!visited[i])
            possible &= dfs_for_topo(i, ans, visited);
    }

    reverse(ans.begin(), ans.end());//Bz recursin will give the ans in reverse..so again reverse for original
    return possible? ans : vector<int> {};
}

int main()
{
    cout<<"enter nodes and edges\n";
    cin>>n>>m;
    v.resize(n+1);

    while (m--)
    {
        int i,j; cin>>i>>j;
        v[i].push_back(j);
    }

    vector<int> ans=topo_by_dfs();
    for(int &i : ans)
        cout<<i<<" ";
    return 0;
}
