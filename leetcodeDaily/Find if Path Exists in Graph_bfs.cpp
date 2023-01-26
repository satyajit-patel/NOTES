// https://leetcode.com/problems/find-if-path-exists-in-graph/description/
#define VIS std::unordered_map<int, bool>
#define ADJ std::unordered_map<int, std::set<int>>
class Solution {
public:
    bool f(int root, int dest, ADJ& adj, VIS& vis) {
        vis[root] = true;
        std::queue<int> q;
        q.push(root);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(node == dest) return true;
            for(auto &child : adj[node]) {
                if(!vis[child]) {
                    q.push(child);
                    vis[child] = true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // prepare adj list
        VIS vis;
        ADJ adj;
        for(auto &row : edges) {
            int u = row[0];
            int v = row[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        return f(source, destination, adj, vis);
    }
};