// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph
class Solution {
public:
    void bfs(int root, vector<std::pair<int, int>> adj[], vector<int>& dist, vector<int>& parent) {
        dist[root] = 0;
        std::queue<pair<int, int>> q;
        q.push({root, dist[root]});
        
        while(!q.empty()) {
            root = q.front().first;
            int rootsDist = q.front().second;
            q.pop();
            
            for(auto &child : adj[root]) {
                int adjNode = child.first;
                int edgeWeight = child.second;
                if(rootsDist+edgeWeight < dist[adjNode]) {
                    dist[adjNode] = rootsDist + edgeWeight;
                    q.push({adjNode, dist[adjNode]});
                    parent[adjNode] = root;
                }
            }
        }
    }
    vector<int> dijkstra(int N, vector<std::pair<int, int>> adj[], int S) {
        std::vector<int> dist(N+1, INT_MAX);
        std::vector<int> parent(N+1);
        for(int i=0; i<=N; i++) parent[i] = i;
        bfs(S, adj, dist, parent);
        // return dist;
        
        if(dist[N] == INT_MAX) return {-1};
        std::vector<int> path;
        int node = N;
        while(parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(S);
        std::reverse(path.begin(), path.end());
        return path;
    }

    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        std::vector<std::pair<int, int>> adj[n+1];
        for(int i=0; i<m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        return dijkstra(n, adj, 1);
    }
};