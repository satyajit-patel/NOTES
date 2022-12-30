//https://leetcode.com/problems/network-delay-time/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //given 1 based indexing and directed graph
        vector<pair<int, int>> adj[n+1];
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        for(auto &row : times) {
            int u = row[0];
            int v = row[1];
            int w = row[2];
            adj[u].push_back({v, w});
        }
        
        priority_queue<pair<int, int>> pq;
        pq.push({dist[k] * -1, k});
        while(!pq.empty()) {
            int cost = pq.top().first * -1;
            int node = pq.top().second;
            pq.pop();
            
            for(auto &it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;
                if(cost + wt < dist[adjNode]) {
                    dist[adjNode] = cost + wt;
                    pq.push({dist[adjNode] * -1, adjNode});
                }
            }
        }
        
        int maxi = INT_MIN;
        for(int i=1; i<=n; i++) {
            if(dist[i] == INT_MAX) return -1;
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};