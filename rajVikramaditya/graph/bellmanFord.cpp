
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
#define endl "\n"

struct node {
    int u,v,w;
    node(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
void bellmanFord(int src, int n, vector<node> &edges) {
    vi dist(n, INT_MAX);
    dist[src] = 0;
    for(int i=1; i<=n-1; i++) {
        for(auto &it : edges) {
            int u = it.u;
            int v = it.v;
            int wt = it.w;
            if(dist[u] + wt < dist[v]) dist[v] = dist[u] + wt;
        }
    }
    //iterate again to check for negative cycle
    for(auto &it : edges) {
        int u = it.u;
        int v = it.v;
        int wt = it.w;
        if(dist[u] + wt < dist[v]) {
            cout<<"there exist a negative cycle\n";
            return;
        }
    }
    for(int i=0; i<n; i++) cout<<dist[i]<<" ";
}
void graphInput() {
    int n,m; cin>>n>>m;
    vector<node> edges;
    for(int i=0; i<m; i++) {
        int u,v,w; cin>>u>>v>>w;
        edges.push_back(node(u,v,w));
    }
    bellmanFord(0, n, edges);
}
int main() {
    graphInput();
    return 0;
}