// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=strongly-connected-components-kosarajus-algo
#define ADJ std::unordered_map<int, std::unordered_set<int>>
#define VIS std::unordered_map<int, bool>
class Solution {
public:
    void revDfs(int root, VIS& vis, ADJ& adj) {
        vis[root] = true;
        for(auto &child : adj[root]) {
            if(!vis[child]) revDfs(child, vis, adj);
        }
    }
    void dfs(int root, VIS& vis, ADJ& adj, stack<int>& st) {
        vis[root] = true;
        for(auto &child : adj[root]) {
            if(!vis[child]) dfs(child, vis, adj, st);
        }
        st.push(root);
    }
    int stronglyConnectedComponents(int v, ADJ& adj) {
        VIS vis;
        std::stack<int> st;
        for(int i=0; i<v; i++) {
            if(!vis[i]) dfs(i, vis, adj, st);
        }
        std::vector<int> topoSort;
        while(!st.empty()) {
            topoSort.push_back(st.top());
            st.pop();
        }
        
        ADJ transpose;
        for(int i=0; i<v; i++) {
            int root = i;
            vis[root] = false;
            for(auto &child : adj[i]) {
                transpose[child].insert(root);
            }
        }
        int scc = 0;
        for(int i=0; i<topoSort.size(); i++) {
            int node = topoSort[i];
            if(!vis[node]) {
                scc++;
                revDfs(node, vis, transpose);
            } 
        }
        return scc;
    }

    int kosaraju(int V, vector<vector<int>>& graph) {
        ADJ adj;
        for(int i=0; i<V; i++) {
            int u = i;
            for(auto &it : graph[i]) {
                int v = it;
                adj[u].insert(v);
            }
        }
        return stronglyConnectedComponents(V, adj);
    }
};