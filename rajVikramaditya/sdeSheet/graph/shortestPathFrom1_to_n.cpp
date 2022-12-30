//link ---> https://codeforces.com/problemset/problem/20/C
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vpi vector<pair<int, int>>

vi zeroOneBfs(int root, vpi adj[]) {
    priority_queue<pair<int, int>> pq;
    vi dist(100005, INT_MAX);
    vi par(100005, -1);
    par[root] = root;
    dist[root] = 0;
    pq.push({dist[root] * -1, root});
    
    while(!pq.empty()) {
        int cost = pq.top().first * -1;
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
    return par;
}
int main() {
    int n, m; cin>>n>>m; 
    vpi adj[n+1];
    for(int i=0; i<m; i++) {
        int u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vi par = zeroOneBfs(1, adj);
    vi ans;
    ans.push_back(n);
    while(par[n] != 1) {
        n = par[n];
        ans.push_back(n);
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    for(auto &it : ans) cout<<it<<" ";
    cout<<endl;
    return 0;
}