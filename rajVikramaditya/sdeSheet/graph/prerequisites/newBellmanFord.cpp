//https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0/?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU
#define vi vector<int>
#define vpi vector<pair<int, int>>
class Solution{
public:
    vi bellmanFordBfs(int root, int n, vpi adj[]) {
        vi dist(n, 100000000);
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
    vector <int> bellman_ford(int V, vector<vector<int>> adjOld, int S) {
        vpi adj[V];
        for(auto &row : adjOld) {
            int u = row[0];
            int v = row[1];
            int w = row[2];
            //directedGraph
            adj[u].push_back({v, w});
        }
        vi ans = bellmanFordBfs(S, V, adj);
        return ans;
    }
};