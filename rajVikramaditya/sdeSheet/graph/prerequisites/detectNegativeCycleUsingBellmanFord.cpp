#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"

struct node {
    int u,v,w;
    node(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
pair<bool, vi> bellmanFordBfs(int root, int n, vector<node> edge) {
    vi dist(n, 1000);
    dist[root] = 0;
    bool isCycle = false;
    for(int i=0; i<n-1; i++) {
        for(auto &it : edge) {
            int u = it.u;
            int v = it.v;
            int wt = it.w;
            if(dist[u] + wt < dist[v]) dist[v] = dist[u] + wt;
        }
    }
    for(auto &it : edge) {
        int u = it.u;
        int v = it.v;
        int wt = it.w;
        if(dist[u] + wt < dist[v]) {
            isCycle = true;
            break;
        }
    }
    return {isCycle, dist};
} 
int main() {
    int n,m; cin>>n>>m;
    vector<node> edge;
    for(int i=0; i<m; i++) {
        int u,v,w; cin>>u>>v>>w;
        //directedGraph
        edge.push_back(node(u,v,w));
    }
    pair<bool, vi> it = bellmanFordBfs(0, n, edge);
    bool cycle = it.first;
    vi ans = it.second;
    if(cycle) cout<<"-ve cycle exist";
    else for(auto &it : ans) cout<<it<<" ";
    return 0;
}