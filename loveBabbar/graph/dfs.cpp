// https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462
#include<bits/stdc++.h>
void f(int root, unordered_map<int, bool>& vis, unordered_map<int, set<int>>& adj, vector<int>& temp) {
    temp.push_back(root);
    vis[root] = true;
    for(auto &child : adj[root]) {
        if(!vis[child]) f(child, vis, adj, temp);
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    // prepare adj list
    unordered_map<int, set<int>> adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].insert(v);
        adj[v].insert(u);
    }
    
    unordered_map<int, bool> vis;
    vector<vector<int>> ans;
    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            vector<int> temp;
            f(i, vis, adj, temp);
            ans.push_back(temp);
        }
    }
    return ans;
}