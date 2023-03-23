// https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-provinces
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
    int numProvinces(vector<vector<int>> adj, int V) {
        DSU dsu(V+1);
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(adj[i][j] == 1) {
                    int u = i+1;
                    int v = j+1;
                    dsu.unionS(u, v);
                }
            }
        }
        int cc = 0;
        for(int node=1; node<=V; node++) if(dsu.parent[node] == node) cc++;
        return cc;
    }
};