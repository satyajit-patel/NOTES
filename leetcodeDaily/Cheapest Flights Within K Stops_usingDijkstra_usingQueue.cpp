// https://leetcode.com/problems/cheapest-flights-within-k-stops/submissions/
#define ADJ std::unordered_map<int, std::set<std::pair<int, int>>>
class Solution {
public:
    std::vector<int> f(int n, ADJ& adj, int src, int k) {
        std::vector<int> dist(n, 1e9);
        std::queue<std::pair<std::pair<int, int>, int>> q;
        dist[src] = 0;
        q.push({{dist[src], src}, 0});
        while(!q.empty()) {
            int cost = q.front().first.first;
            int node = q.front().first.second;
            int stop = q.front().second;
            q.pop();
            for(auto &child : adj[node]) {
                int adjNode = child.first;
                int adjCost = child.second;
                int totCost = cost + adjCost;
                if(totCost < dist[adjNode] && stop <= k) {
                    dist[adjNode] = totCost;
                    q.push({{dist[adjNode], adjNode}, stop+1});
                }
            }
        }
        return dist;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // make adj list
        ADJ adj;
        for(auto &row : flights) {
            int u = row[0];
            int v = row[1];
            int w = row[2];
            adj[u].insert({v, w});
        }
        std::vector<int> dist = f(n, adj, src, k);
        if(dist[dst] != 1e9) return dist[dst];
        return -1;
    }
};