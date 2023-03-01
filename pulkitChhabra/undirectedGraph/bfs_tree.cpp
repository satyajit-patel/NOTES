#include<bits/stdc++.h>

using namespace std;


//we required two things--->a queue and a parent array
void bfs(vector<vector<int>> v, int n, int root)
{
    vector<int> parent(n+1);
    parent[root]=0; //ie parent of root is 0
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int current= q.front();

        cout<<current<<" "; //ist root will be printed i.e 1 in this case
        q.pop();

        //add the neighbour nodes to queue
        for(int nb : v[current])
        {
            //except the root
            if(nb != parent[current])
            {
                q.push(nb);
                parent[nb]=current; //nb of parent will become 1
            }
        }
    }
    
}
void bfs_level_wise(vector<vector<int>> v, int n, int root)
{
    vector<int> parrent(n+1);
    parrent[root]=0;

    queue<int> q;
    q.push(root);


    while (!q.empty())
    {
        int level= q.size();
        while (level--)
        {
            int current= q.front();

            cout<<current<<" ";
            q.pop();

            for(int nb : v[current])
                if(nb != parrent[current])
                {
                    q.push(nb);
                    parrent[nb]=current;
                }
        }
        cout<<"\n";
    }
    
}
int main()
{
    cout<<"enter no of node\n";
    int n; cin>>n;
    vector<vector<int>> vec(n+1); //of size n+1

    for (int i = 1; i <= n-1; i++)
    {
        int u,v; cin>>u>>v;

        //connecting the edge
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    //printing the neighbour nodes
    for (int i = 1; i <= n; i++)
    {
        cout<<"neighbour of "<<i<<"----> ";
        for(int nb : vec[i])
            cout<<nb<<" ";
        cout<<"\n";
    }
    //bfs(vec,n,1);
    bfs_level_wise(vec,n,1);
    return 0;
}