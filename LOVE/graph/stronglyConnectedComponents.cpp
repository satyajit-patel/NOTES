// https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151
#include<bits/stdc++.h>
#define ADJ unordered_map<int, set<int>>
#define VIS unordered_map<int, bool>
void revDfs(int root, VIS& vis, ADJ& adj) {
    vis[root] = true;
    for(auto &child : adj[root]) {
        if(!vis[child]) revDfs(child, vis, adj);
    }
}
void dfs(int root, VIS& vis, ADJ& adj, stack<int>& st) {
    vis[root] = true;
    for(auto &child : adj[root]) {
        if(!vis[child]) dfs(child, vis, adj, st);
    }
    st.push(root);
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
	// prepare adj list
    ADJ adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].insert(v);
    }
    
    VIS vis;
    stack<int> st;
    for(int i=0; i<v; i++) {
        if(!vis[i]) dfs(i, vis, adj, st);
    }
    vector<int> topoSort;
    while(!st.empty()) {
        topoSort.push_back(st.top());
        st.pop();
    }
    
    ADJ transpose;
    for(int i=0; i<v; i++) {
        for(auto &child : adj[i]) {
            transpose[child].insert(i);
        }
    }
    
    VIS vis1;
    int scc = 0;
    for(int i=0; i<topoSort.size(); i++) {
        int node = topoSort[i];
        if(!vis1[node]) {
            scc++;
            revDfs(node, vis1, transpose);
        } 
    }
    return scc;
}