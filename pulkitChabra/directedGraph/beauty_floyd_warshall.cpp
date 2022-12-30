#include<bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> v;//bez we have to store edge with weight at a time
int n;

vector<vector<int>> floyd_warshall()
{
    int INF=10000;
    vector<vector<int>> distance(n+1, vector<int>(n+1, INF));//initialy all columns initialized with infinity

    //O(M)
    for (int i = 1; i<=n; i++)
    {
        distance[i][i]=0;//all diagonal will be zero

        //iterate the edge of that node
        for(auto e : v[i]){//O(1) beoz its for only 2 edge
            //if multiple edge are going the select the one with minimum weight
            distance[i][e.first]=min(distance[i][e.first], e.second);
        }
    }
    
    //O(N^3)
    for (int k=1; k<=n; k++)//k is no of phases
    {
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
            {
                if(distance[i][k] != INF and distance[k][j] != INF)
                    distance[i][j]=min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }
    return distance;
}
int main()
{
    cout<<"enter no of nodes and edges\n";
    int m; cin>>n>>m;
    v.resize(n+1);

    while(m--)
    {
        int i,j,w; cin>>i>>j>>w;

        //connect the edge
        v[i].push_back({j,w});//it is for only directed graph
        //v[j].push_back({i,w});
    }

    auto distance=floyd_warshall();//returns a 2D vector
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<"v"<<"["<<i<<"]"<<"["<<j<<"]"<<" distance is---->"<<distance[i][j]<<"\n";
    }
    return 0;
}