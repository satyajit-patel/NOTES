// https://www.codingninjas.com/codestudio/problems/topological-sort_985252?leftPanelTab=0
#include<bits/stdc++.h>
#define ADJ unordered_map<int, set<int>>
#define VIS unordered_map<int, bool>
void dfs(int root, VIS& vis, ADJ& adj, stack<int>& st) {
    vis[root] = true;
    for(auto &child : adj[root]) {
        if(!vis[child]) dfs(child, vis, adj, st);
    }
    st.push(root);
}
vector<int> topologicalSort(vector<pair<int,int>>& edges, int N, int M) {
    // prepare adj list
    ADJ adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].insert(v);
    }
    
    VIS vis;
    stack<int> st;
    for(int i=1; i<=N; i++) {
        if(!vis[i]) dfs(i, vis, adj, st);
    }
    
    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
} 
