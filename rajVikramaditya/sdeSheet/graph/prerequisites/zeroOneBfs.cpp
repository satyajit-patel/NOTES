//link ---> 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vpi vector<pair<int, int>>

vi zeroOneBfs(int root, vpi adj[]) {
    deque<pair<int, int>> dq;
    vi dist(100005, INT_MAX);
    dist[root] = 0;
    dq.push_front({root, dist[root]});
    
    while(!dq.empty()) {
        int node = dq.front().first;
        int cost = dq.front().second;
        dq.pop_front();
        
        for(auto &it : adj[node]) {
            int adjNode = it.first;
            int edgeCost = it.second;
            if(cost + edgeCost < dist[adjNode]) {
                dist[adjNode] = cost + edgeCost;
                if(edgeCost == 0) dq.push_front({adjNode, dist[adjNode]});
                else  dq.push_back({adjNode, dist[adjNode]});
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