//link --> https://bit.ly/3twUKJP
#include<bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
void revDfs(int root, vi &vis, vi transpose[], vi &scc) {
    scc.push_back(root);
    vis[root] = 1;
    for(auto &it : transpose[root]) {
        if(!vis[it]) revDfs(it, vis, transpose, scc);
    }
}
void topoSortDfs(int root, vi &vis, vi adj[], stack<int> &st) {
    vis[root] = 1;
    for(auto &it : adj[root]) {
        if(!vis[it]) topoSortDfs(it, vis, adj, st);
    }
    st.push(root);
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges) {
    // Write your code here.
    vi vis(n, 0);
    vi adj[n];
    for(auto &row : edges) {
        int u = row[0];
        int v = row[1];
        //given directed graph
        adj[u].push_back(v);
    }
    
    stack<int> st;
    for(int i=0; i<n; i++) {
        if(!vis[i]) topoSortDfs(i, vis, adj, st);
    }
    
    vi transpose[n];
    for(int i=0; i<n; i++) {
        vis[i] = 0;
        for(auto &it : adj[i]) {
            transpose[it].push_back(i);
        }
    }
    
    vii ans;
    vi scc;
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(!vis[node]) {
            revDfs(node, vis, transpose, scc);
            ans.push_back(scc);
            scc.clear();
        }
    }
    return ans;
}