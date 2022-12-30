//start with root..print it, popit
//explore its adjacent nodes(explore the unvisited node only)
//then update the root
#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> v;
void bfs_traverse(int root_node)
{
    queue<int> q;
    vector<bool> visited(n+1, 0);

    q.push(root_node);
    visited[root_node]=1;

    while (!q.empty()) //while queue is not empty
    {
        int i=q.front();
        cout<<i<<" ";
        q.pop();

        //explore its adjacent nodes
        for(int nb : v[i])
        {
            if(visited[nb])//i.e if visited == 1 then do nothing
                continue;
            
            q.push(nb);
            visited[nb]=1;
        }
    }
    cout<<"\n";
}

//print the distance of every node from its root
vector<int> bfs_distance(int root_node)
{
    queue<int> q;
    vector<int> distancee(n+1, -1);//initially initialize with -1

    q.push(root_node);
    distancee[root_node]=0;

    while(!q.empty())
    {
        int i=q.front();
        q.pop();

        for(int nb : v[i])
        {
            if(distancee[nb] != -1) //if not -1 i.e it is alrady visited so don't do anything
                continue;

            q.push(nb);//push all adjacent nodes
            distancee[nb]= distancee[i] + 1;
        }
    }
    cout<<"\n";
    return distancee;
}
int main()
{
    cout<<"enter no of node and edge\n";
    int edge; cin>>n>>edge;
    v.resize(n+1);//becz row size is must

    //teke inputs
    while (edge--)
    {
        int i,j; cin>>i>>j;

        //connect the edge
        v[i].push_back(j);
        v[j].push_back(i);
    }

    bfs_traverse(1);

    vector<int> distance = bfs_distance(1);
    for (int i = 1; i <= n; i++)
    {
        cout<<"node "<<i<<" distane is------->"<<distance[i]<<"\n";
    }
    
    return 0;
}
