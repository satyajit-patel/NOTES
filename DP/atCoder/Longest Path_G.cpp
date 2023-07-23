// link => https://atcoder.jp/contests/dp/tasks/dp_g
#include<bits/stdc++.h>
#define int     long long
#define vi      std::vector<int>
#define vvi     std::vector<vector<int>>
#define VIS     std::unordered_map<int, int>
#define ADJ     std::unordered_map<int, std::unordered_set<int>>
// -------------------------------------------------------------------------------------------

// global variable
ADJ adj;
VIS vis;
vi dist;

void f(int root) {
    vis[root] = 1;
    for(auto &child : adj[root]) {
        if(!vis[child]) f(child);
        dist[root] = std::max(dist[root], 1 + dist[child]);
    }
}

void input() {
    int n, m; std::cin>>n>>m;
    adj.clear();
    while(m--) {
       int u, v; std::cin>>u>>v;
       adj[u].insert(v);
    }
    
    vis.clear();
    dist.resize(n+1, 0);
    for(int root=0; root<=n; root++) {
        if(!vis[root]) f(root);
    }
    int maxi = 0;
    for(int root=1; root<=n; root++) maxi = std::max(maxi, dist[root]);
    std::cout<<maxi<<"\n";
}

// -------------------------------------------------------------------------------------------
signed main() {
    input();
	return 0;
}