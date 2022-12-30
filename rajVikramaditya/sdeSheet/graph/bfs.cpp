//link --> https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
void bfs(int root, vector<int> &vis, vector<int> adj[], vector<int> &ans) {
    vis[root] = 1;
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto &it : adj[node]) {
            if(!vis[it]) {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
}
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    vector<int> ans;
    vector<int> vis(V, 0);
    //for(int i=0; i<V; i++) {
        //if(!vis[i]) bfs(i, vis, adj, ans);
    //}
    bfs(0, vis, adj, ans);
    return ans;
}