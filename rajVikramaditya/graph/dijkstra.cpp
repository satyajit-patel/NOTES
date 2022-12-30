
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
#define endl "\n"

vector<pair<int, int>> adj[100005];
int n;
void dfsDijkstra(int src) {
    priority_queue<pair<int, int>> pq;
    vi distance(n+1, INT_MAX);
    distance[src] = 0;
    pq.push({0, src});
    
    while(!pq.empty()) {
        int dist = pq.top().first * -1;
        int node = pq.top().second;
        pq.pop();
        
        if(distance[node] != dist) continue;
        for(auto &it:adj[node]) {
            if(dist + it.second < distance[it.first]) {
                distance[it.first] = dist+it.second;
                pq.push({-1 * distance[it.first], it.first});
            }
        }
    }
    for(int i=1; i<=n; i++) cout<<i<<" "<<distance[i]<<endl;
}
void graphInput() {
    int m; cin>>n>>m;
    for(int i=1; i<=m; i++) {
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfsDijkstra(1);
}
int main() {
    graphInput();
    return 0;
}