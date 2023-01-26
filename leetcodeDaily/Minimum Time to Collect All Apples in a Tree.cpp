// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/
#define ADJ std::unordered_map<int, std::set<int>>
#define VIS std::unordered_map<int, bool>
class Solution {
public:
    int dfs(ADJ& adj, VIS& vis, vector<bool>& hasApple, int root = 0) {
        vis[root] = true;
        int time = 0;
        for(auto &child : adj[root]) {
            if(!vis[child]) {
                int val = dfs(adj, vis, hasApple, child);
                if(val || hasApple[child]) time += 2 + val;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // prepare adj list
        ADJ adj;
        VIS vis;
        for(auto &row : edges) {
            int u = row[0];
            int v = row[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        return dfs(adj, vis, hasApple);
    }
};