#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<pair<int, int>>> v;
vector<int> dijkstra_single_source(int src)
{
    vector<int> distance(n+1, 100000);//intialy store some infinity number
    set<pair<int, int>> s;

    distance[src]=0;
    s.insert({0,src});

    while(!s.empty())//do this untill set is not empty
    {
        auto it=s.begin();
        int node=it->second;
        cout<<node<<" ";
        s.erase(it);

        //iterate its neighbour nodes
        for(auto e : v[node])
        {
            int nb=e.first, w=e.second;

            //relaxsation
            if(distance[node]+w < distance[nb])
            {
                s.erase({distance[nb], nb});
                distance[nb]=distance[node]+w;
                s.insert({distance[nb], nb});//just erasing and updating with new
            }
        }
    }
    return distance;
}


int main()
{
    cout<<"enter no of nodes and edges\n";
    cin>>n>>m;
    v.resize(n+1);

    while(m--)
    {
        int i,j,w; cin>>i>>j>>w;

        //connect the edge with weight
        v[i].push_back({j,w});
        v[j].push_back({i,w});
    }
    
    cout<<"\npath is this---->\n";
    vector<int> d=dijkstra_single_source(1);
    cout<<"\nand distance of every nodes are bellow\n";
    for(int i=1; i<=n; i++)
        cout<<"node "<<i<<" distance is---->"<<d[i]<<"\n";
    return 0;
}