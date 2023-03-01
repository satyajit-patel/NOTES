// https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002
#include <bits/stdc++.h> 
void bfs(int root, unordered_map<int, bool>& vis, unordered_map<int, set<int>>& adj, vector<int>& ans) {
    queue<int> q;
    q.push(root);
    vis[root] = true;
    
    while(!q.empty()) {
        root = q.front();
        q.pop();
        ans.push_back(root);
        for(auto &child : adj[root]) {
            if(!vis[child]) {
                q.push(child);
                vis[child] = true;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
    // prepare adj list
    unordered_map<int, set<int>> adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    
    unordered_map<int, bool> vis;
    vector<int> ans;
    for(int i=0; i<vertex; i++) {
        if(!vis[i]) bfs(i, vis, adj, ans);
    }
    return ans;
 
}