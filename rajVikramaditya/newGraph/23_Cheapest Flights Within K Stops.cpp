// https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=cheapest-flights-within-k-stops
class Solution {
public:
    void dijkstra(int root, vector<pair<int, int>> adj[], vector<int>& dist, int dest, int K) {
        dist[root] = 0;
        std::queue<std::pair<int, std::pair<int, int>>> q;
        q.push({0, {root, dist[root]}});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            root = it.second.first;
            int rootsDist = it.second.second;
            if(stops > K) continue;
            
            for(auto &child : adj[root]) {
                int adjNode = child.first;
                int edgeWeight = child.second;
                if(rootsDist+edgeWeight < dist[adjNode]) {
                    dist[adjNode] = rootsDist+edgeWeight;
                    q.push({stops+1, {adjNode, dist[adjNode]}});
                }
            }
        }
    }

    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        std::vector<std::pair<int, int>> adj[n];
        for(auto &row : flights) {
            int u = row[0];
            int v = row[1];
            int w = row[2];
            adj[u].push_back({v, w});
        }
        std::vector<int> dist(n, INT_MAX);
        dijkstra(src, adj, dist, dst, K);
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};