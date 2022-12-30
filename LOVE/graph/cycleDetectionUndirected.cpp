// https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?leftPanelTab=1
#include<bits/stdc++.h>
#define ADJ unordered_map<int, set<int>>
#define VIS unordered_map<int, bool>
bool dfs(int root, VIS &vis, ADJ &adj, int parent) {
    vis[root] = true;
    for(auto &child : adj[root]) {
        if(!vis[child]) {
            if(dfs(child, vis, adj, root)) return true;
        }
        else if(child != parent) return true;
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m) {
    // prepare adj list
    ADJ adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].insert(v);
        adj[v].insert(u);
    }
    
    VIS vis;
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            if(dfs(i, vis, adj, -1)) return "Yes";
        }
    }
    return "No";
}
