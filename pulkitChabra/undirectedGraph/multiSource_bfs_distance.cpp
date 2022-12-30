#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> v;
vector<int> bfs_distance(vector<int> root_node_s)
{
    queue<int> q;
    vector<int> distancee(n+1, -1);

    for(int root_node : root_node_s){
        q.push(root_node);
        distancee[root_node]=0;
    }

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

    vector<int> distance = bfs_distance({1,4});
    cout<<"\n";
    for (int i = 1; i <= n; i++)
    {
        cout<<"node "<<i<<" distane is------->"<<distance[i]<<"\n";
    }
    
    return 0;
}
