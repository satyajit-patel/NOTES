#include<bits/stdc++.h>

using namespace std;
vector<int> get_path_between_2node(int src, int dest, vector<vector<int>> v, int n)//source and destination
{
    vector<int> par(n+1,-1);//parent vector
    vector<int> dist(n+1,-1);//distance vector
    queue<int> q;

    q.push(src);
    dist[src]=0;

    while (!q.empty())//do this intill queue gets empty
    {
        int current=q.front();
        q.pop();

        for(int neighbour : v[current])
        {
            if(dist[neighbour] != -1)// if distance is not empty i.e its already updated so do nothing
                continue;
            q.push(neighbour);
            dist[neighbour]=dist[current] + 1;//i.e height = source's height + 1;
            par[neighbour]=current;
        }
    }
    if(dist[dest] == -1)
        return {};//return empty vector i.e invalid path(we didn't reach to destintion)
    vector<int> path;

    //now to track the path we need to climb up till dest and reverse it to find the result in ascending
    int root=dest;
    while(root != -1) //bzz initialy we initialize src's parent = -1(then we only updates its neighbours not src) 
    {
        path.push_back(root);
        root=par[root];//now climb to its parent
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    cout<<"enter no of nodes and edges\n";
    int n,edge; cin>>n>>edge;

    vector<vector<int>> v(n+1);//adjacent 2D vecctor
    while (edge--)
    {
        int i,j; cin>>i>>j;
        v[i].push_back(j);
        v[j].push_back(i);
    }

    int src,dest; cin>>src>>dest;
    vector<int> path=get_path_between_2node(src,dest,v,n);
    cout<<"\n";
    for(int i : path)
        cout<<i<<" ";
    return 0;    
}