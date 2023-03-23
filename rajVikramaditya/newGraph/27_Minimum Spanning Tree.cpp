// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree
class DSU {
public:
    vector<int> parent, size;
    DSU(int N) {
        parent.resize(N);
        for(int i=0; i<N; i++) parent[i] = i;
        size.resize(N, 1);
    }
    
    int findParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }   
    
    void unionS(int u, int v) {
        int nu = findParent(u);
        int nv = findParent(v);
        if(nu == nv) return;
        if(size[nu] < size[nv]) {
            parent[nu] = nv;
            size[nv] += size[nu];
        }
        else {
            parent[nv] = nu;
            size[nu] += size[nv];
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        int mstWeight = 0;
        DSU dsu(V);
        std::vector<std::pair<int, std::pair<int, int>>> edges;
        for(int root=0; root<V; root++) {
            for(auto &child : adj[root]) {
                int u = root;
                int v = child[0];
                int w = child[1];
                edges.push_back({w, {u, v}});
            }
        }
        std::sort(edges.begin(), edges.end());
        for(auto &it : edges) {
            int w = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(dsu.findParent(u) != dsu.findParent(v)) {
                mstWeight += w;
                dsu.unionS(u, v);
            }
        }
        return mstWeight;
    }
};