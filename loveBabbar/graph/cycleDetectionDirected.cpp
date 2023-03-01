// https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=1
#include<bits/stdc++.h>
#define ADJ unordered_map<int, set<int>>
#define VIS unordered_map<int, int>
bool dfs(int root, VIS& vis, ADJ& adj) {
    vis[root] = 2;
    for(auto &child : adj[root]) {
        if(!vis[child]) {
            if(dfs(child, vis, adj)) return true;
        }
        else if(vis[child] == 2) return true;
    }
    vis[root] = 1;
    return false;
}
int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    // prepare adj list
    ADJ adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].insert(v);
    }
    
    VIS vis;
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            if(dfs(i, vis, adj)) return 1;
        }
    }
    return 0;
}