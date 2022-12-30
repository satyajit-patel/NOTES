//link --> https://bit.ly/3tps98W
#define vi vector<int>
bool dfs(int root, vi &col, vi adj[], int color = 0) {
    col[root] = color;
    for(auto &it : adj[root]) {
        if(col[it] == -1) {
            if(!dfs(it, col, adj, !color)) return false;
        }
        else if(col[it] == col[root]) return false;
    }
    return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
    int n = edges.size();
    vi col(n, -1);
    vi adj[n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<edges[i].size(); j++) {
            if(edges[i][j] == 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for(int i=0; i<n; i++) {
        if(col[i] == -1) {
            if(!dfs(i, col, adj)) return false;
        }
    }
    return true;
}