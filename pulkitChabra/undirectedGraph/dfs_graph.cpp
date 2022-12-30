#include<bits/stdc++.h>

using namespace std;

int node;
vector<vector<int>> v;
vector<int> parent;
vector<bool> visited;

void dfs_traverse(int root_node)
{
    cout<<root_node<<" ";
    visited[root_node]=true;

    //now visit its neighbour nodes
    for(int nb : v[root_node])
    {
        if(!visited[nb])//if not visited i.e visited[nb]==false
            dfs_traverse(nb);
    }
}
int main()
{
    cout<<"enter no of nodes and edges\n";
    int edge; cin>>node>>edge;

    v.resize(node+1);
    visited.assign(node+1,0);

    while (edge--)
    {
        int i,j; cin>>i>>j;
        v[i].push_back(j);
        v[j].push_back(i);
    }
    dfs_traverse(1);
    return 0;
}