#define VIS std::unordered_map<int, int>
#define ADJ std::unordered_map<int, std::unordered_set<int>>
class Solution {
private:
    int timer;
    std::vector<int> in, low;
    void dfs(int root, int parent, VIS& vis, ADJ& adj, vector<vector<int>> &bridges) {
        vis[root] = 1;
        in[root] = low[root] = timer++;
        for (auto child : adj[root]) {
            if (child == parent) continue;
            if (vis[child] == 0) {
                dfs(child, root, vis, adj, bridges);
                low[root] = min(low[child], low[root]);
                if (low[child] > in[root]) bridges.push_back({child, root});
            }
            else low[root] = min(low[root], in[child]);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> bridges;
        timer = 1;
        in.resize(n);
        low.resize(n);
        ADJ adj;
        for(auto &row : connections) {
            int u = row[0];
            int v = row[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        VIS vis;
        for(int root=0; root<n; root++) if(!vis[root]) dfs(root, -1, vis, adj, bridges);
        return bridges;
    }
};