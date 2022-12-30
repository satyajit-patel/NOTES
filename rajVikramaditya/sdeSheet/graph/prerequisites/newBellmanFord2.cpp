//https://bit.ly/3GwAf3A
#define vi vector<int>
#define vpi vector<pair<int, int>>
vi bellmanFordBfs(int root, int n, vpi adj[]) {
    vi dist(n+1, 1000000000);
    dist[root] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({dist[root] * -1, root});
    while(!pq.empty()) {
        root = pq.top().second;
        int cost = pq.top().first * -1;
        pq.pop();
        for(auto &it : adj[root]) {
            int adjNode = it.first;
            int wt = it.second;
            if(cost + wt < dist[adjNode]) {
                dist[adjNode] = cost + wt;
                pq.push({dist[adjNode] * -1, adjNode});
            }
        }
    }
    return dist;
} 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &adjOld) {
    vpi adj[n+1];
    for(auto &row : adjOld) {
        int u = row[0];
        int v = row[1];
        int w = row[2];
        //directedGraph
        adj[u].push_back({v, w});
    }
    vi ans = bellmanFordBfs(src, n, adj);
    return ans[dest];
}