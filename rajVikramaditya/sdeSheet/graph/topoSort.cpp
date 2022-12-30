
//link --> https://bit.ly/33bapUo
#define vi vector<int> 
#include<bits/stdc++.h>
void dfs(int root, vi &vis, vi adj[], stack<int> &st) {
    vis[root] = 1;
    for(auto &it : adj[root]) {
        if(!vis[it]) dfs(it, vis, adj, st);
    }
    st.push(root);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int V, int e)  {
    // Write your code here
    vi ans;
    stack<int> st;
    vi vis(V, 0);
    int cc = 0;
    vi adj[V];
    for(auto &it : edges) {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
    }
    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            dfs(i, vis, adj, st);
            cc++;
        }
    }
    //ans.push_back(cc);
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}