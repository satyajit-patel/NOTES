//link ---> 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vpi vector<pair<int, int>>

void zeroOneBfs(int root, vpi adj[]) {
    priority_queue<pair<int, int>> pq;
    vi dist(100005, INT_MAX);
    vi par(100005, -1);
    par[root] = root;
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
                par[adjNode] = node;
                dist[adjNode] = cost + wt;
                pq.push({dist[adjNode] * -1, adjNode});
            }
        }
    }
    int x = 4; //destination node
    cout<<x<<" ";
    while(par[x] != 1) {
        x = par[x]; //parent of dest i.e from where it came
        cout<<x<<" ";
    }
}
int main() {
    int n, m; cin>>n>>m; 
    vpi adj[n+1];
    for(int i=0; i<m; i++) {
        int u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    zeroOneBfs(1, adj);

    return 0;
}