//link --> https://practice.geeksforgeeks.org/problems/topological-sort/1
void dfs(int root, vector<int> &vis, vector<int> adj[], stack<int> &st) {
    vis[root] = 1;
    for(auto &it : adj[root]) {
        if(!vis[it]) dfs(it, vis, adj, st);
    }
    st.push(root);
}
vector<int> topoSort(int V, vector<int> adj[]) {
    // code here
    vector<int> ans;
    stack<int> st;
    vector<int> vis(V, 0);
    for(int i=0; i<V; i++) {
        if(!vis[i]) dfs(i, vis, adj, st);
    }
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}