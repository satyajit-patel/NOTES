#include<bits/stdc++.h>

using namespace std;
void dfs(int root_node, int parent_node, vector<vector<int>> v)
{
    cout<<root_node<<" ";
    //iterate over its adjacent(neighbour) nodes
    for(int nb : v[root_node])
    {
        if(nb == parent_node)//we make recurcive call on childs...so if nb == parent then don't do anything
            continue;

        //now make changes and call
        //root_node = nb
        //parent_node = root_node
        dfs(nb,root_node,v);
    }
}
int main()
{
    cout<<"enter no of nodes\n";
    int n; cin>>n;
    vector<vector<int>> vec(n+1);
    //teke input
    for (int i = 0; i < n-1; i++)
    {
        int u,v; cin>>u>>v;

        //add edge
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1,0,vec);
    return 0;
}