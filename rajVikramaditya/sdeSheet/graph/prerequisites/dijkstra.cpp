//link ---> 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vpi vector<pair<int, int>>

vi zeroOneBfs(int root, vpi adj[]) {
    priority_queue<pair<int, int>> pq;
    vi dist(100005, INT_MAX);
    dist[root] = 0;
    pq.push({dist[root] * -1, root}); //mul -1 at time of push
    
    while(!pq.empty()) {
        int cost = pq.top().first * -1;//mul -1 at time of retrive
        int node = pq.top().second;
        pq.pop();
        
        for(auto &it : adj[node]) {
            int adjNode = it.first;
            int wt = it.second;
            if(cost + wt < dist[adjNode]) {
                dist[adjNode] = cost + wt;
                pq.push({dist[adjNode] * -1, adjNode});
            }
        }
    }
    return dist;
}
int main() {
    int n, m; cin>>n>>m; 
    vpi adj[n+1];
    for(int i=0; i<m; i++) {
        int u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vi ans = zeroOneBfs(1, adj);
    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    return 0;
}