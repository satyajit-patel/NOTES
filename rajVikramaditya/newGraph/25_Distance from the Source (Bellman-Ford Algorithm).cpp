// https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU
#define vi std::vector<int>
#define vpi std::vector<std::pair<int, int>>
class Solution {
public:
    void dijkstra(int root, vpi adj[], vi& dist) {
        dist[root] = 0;
        std::priority_queue<std::pair<int, int>> pq;
        pq.push({dist[root] * -1, root});
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int rootsDist = it.first * -1;
            root = it.second;
            
            for(auto &child : adj[root]) {
                int adjNode = child.first;
                int edgeWeight = child.second;
                if(rootsDist+edgeWeight < dist[adjNode]) {
                    dist[adjNode] = rootsDist+edgeWeight;
                    pq.push({dist[adjNode] * -1, adjNode});
                }
            }
        }
    }

    bool isNegativeCycle(int root, vector<vector<int>>& edges, int N) {
        vi dist(N, 1e8);
        dist[root] = 0;
        for(int i=0; i<N-1; i++) {
            for(auto &row : edges) {
                int u = row[0];
                int v = row[1];
                int w = row[2];
                if(dist[u]+w < dist[v]) dist[v] = dist[u]+w;
            }
        }
        for(auto &row : edges) {
            int u = row[0];
            int v = row[1];
            int w = row[2];
            if(dist[u]+w < dist[v]) return true;
        }
        return false;
    }

    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        if(isNegativeCycle(S, edges, V)) return {-1};
        vpi adj[V];
        for(auto &row : edges) {
            int u = row[0];
            int v = row[1];
            int w = row[2];
            adj[u].push_back({v, w});
        }
        vi dist(V, 1e8);
        dijkstra(S, adj, dist);
        return dist;
    }
};
