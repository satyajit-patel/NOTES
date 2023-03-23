// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix
class Solution {
public:
    void bfs(int root, vector<vector<int>> adj[], vector<int>& dist) {
        dist[root] = 0;
        std::queue<pair<int, int>> q;
        q.push({root, dist[root]});
        
        while(!q.empty()) {
            root = q.front().first;
            int rootsDist = q.front().second;
            q.pop();
            
            for(auto &child : adj[root]) {
                int adjNode = child[0];
                int edgeWeight = child[1];
                if(rootsDist+edgeWeight < dist[adjNode]) {
                    dist[adjNode] = rootsDist + edgeWeight;
                    q.push({adjNode, dist[adjNode]});
                }
            }
        }
    }
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        std::vector<int> dist(V, INT_MAX); // 0 based indexing
        bfs(S, adj, dist);
        return dist;
    }
};