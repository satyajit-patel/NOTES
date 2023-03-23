// https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=/number-of-ways-to-arrive-at-destination
class Solution {
public:
    int MOD = (int)1e9 + 7;
    void dijkstra(long long root, vector<pair<long long, long long>> adj[], vector<long long>& dist, vector<long long>& ways) {
        dist[root] = 0;
        ways[root] = 1;
        std::priority_queue<std::pair<long long, long long>> pq;
        pq.push({dist[root] * -1, root});
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            long long rootsDist = it.first * -1;
            root = it.second;
            
            for(auto &child : adj[root]) {
                long long adjNode = child.first;
                long long edgeWeight = child.second;
                if(rootsDist+edgeWeight < dist[adjNode]) {
                    dist[adjNode] = rootsDist+edgeWeight;
                    pq.push({dist[adjNode] * -1, adjNode});
                    ways[adjNode] = ways[root];
                }
                else if(rootsDist+edgeWeight == dist[adjNode]) ways[adjNode] = (ways[root] + ways[adjNode]) % MOD;
            }
        }
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        std::vector<std::pair<long long, long long>> adj[n];
        for(auto &row : roads) {
            long long u = row[0];
            long long v = row[1];
            long long w = row[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        std::vector<long long> dist(n, 1e18);
        std::vector<long long> ways(n, 0);
        dijkstra(0, adj, dist, ways);
        return ways[n-1] % MOD;
    }
};