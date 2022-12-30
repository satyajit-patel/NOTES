//https://leetcode.com/problems/number-of-operations-to-make-network-connected/
class DSU {
public:
    vector<int> parent, height;
    DSU(int n) {
        parent.resize(n);
        height.resize(n, 0);
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
    }
    int findRoot(int u) {
        if(u == parent[u]) return u;
        return parent[u] = findRoot(parent[u]);
    }
    void unionH(int u, int v) {
        int pu = findRoot(u);
        int pv = findRoot(v);
        if(pu == pv) return;
        if(height[pu] < height[pv]) parent[pu] = pv;
        else if(height[pu] > height[pv]) parent[pv] = pu;
        else {
            parent[pu] = pv;
            height[pv]++;
        }
    }
};
class Solution {
public:
    void dfs(int root, vector<int> adj[], vector<int> &vis) {
        vis[root] = 1;
        for(auto &it : adj[root]) {
            if(!vis[it]) dfs(it, adj, vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& conn) {
        
        
        int extraEdge = 0;
        DSU dsu(n);
        for(auto &row : conn) {
            if(dsu.findRoot(row[0]) != dsu.findRoot(row[1])) 
                dsu.unionH(row[0], row[1]);
            else
                extraEdge++;
        }
        int cc = 0;
        for(int i=0; i<n; i++) {
            if(dsu.parent[i] == i) cc++;
        }
        int requiredEdgesToJoinRest = cc-1;
        if(extraEdge < requiredEdgesToJoinRest) return -1;
        return requiredEdgesToJoinRest;
        
        
        // vector<int> adj[n];
        // for(auto &row : conn) {
        //     adj[row[0]].push_back(row[1]);
        //     adj[row[1]].push_back(row[0]);
        // }
        // vector<int> vis(n, 0);
        // if(conn.size() < n-1) return -1;
        // int cc = 0;
        // for(int i=0; i<n; i++) {
        //     if(!vis[i]) {
        //         cc++;
        //         dfs(i, adj, vis);
        //     }
        // }
        // return cc-1;
        
    }
};