//print the level of every node
//and also find the number of child node(sub tree) of a perticular node including itself
#include<bits/stdc++.h>

using namespace std;

int levl_DP[1001]={}; //i.e empty table
int subtree[1001]={};

void dfs_level(int root_node, int parent_node, vector<vector<int>> v)
{
    cout<<root_node<<" ";

    levl_DP[root_node]=levl_DP[parent_node] + 1;
    subtree[root_node]=1; //becoz including the node itself

    for(int nb : v[root_node])
    {
        if(nb == parent_node)
            continue;

        dfs_level(nb,root_node,v);
        subtree[root_node] += subtree[nb];
    }
}
int main()
{
    cout<<"enter no of node\n";
    int n; cin>>n;
    vector<vector<int>> vec(n+1); //we must give the row size
    for (int i = 0; i < n-1; i++)
    {
        int u,v; cin>>u>>v;

        //add edge
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs_level(1,0,vec);
    cout<<"\n";
    for (int i = 1; i <= n; i++)
    {
        cout<<"level of "<<i<<" is---->"<<levl_DP[i]<<"\n";
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<"no of child of "<<i<<" is---->"<<subtree[i]<<"\n";
    }
    return 0;
}