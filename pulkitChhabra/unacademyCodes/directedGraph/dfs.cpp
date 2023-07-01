#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
vector<bool> visited;
int node;

void dfs_traverse(int root_node)
{
    cout<<root_node<<" ";
    visited[root_node]=1;

    for(int nb : v[root_node])
    {
        if(!visited[nb])//if neighbour is not visited
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

        //conect the arraow
        v[i].push_back(j);
    }
    //dfs_traverse(1);
    //or
    //instead of traverse from root, we can traverse from every node
    for (int i = 1; i <= node; i++)
    {
        if(!visited[i])
            dfs_traverse(i);
    }
     
    return 0;
}
