// https://practice.geeksforgeeks.org/problems/connecting-the-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=connecting-the-graph
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
    int Solve(int n, vector<vector<int>>& edge) {
        DSU dsu(n);
        int extraEdge = 0;
        for(auto &row : edge) {
            int u = row[0];
            int v = row[1];
            if(dsu.findParent(u) != dsu.findParent(v)) dsu.unionS(u, v);
            else extraEdge++;
        }
        int cc = 0;
        for(int node=0; node<n; node++) if(dsu.parent[node] == node) cc++;
        int ropeNeedToJoinAllNetwork = cc-1;
        if(extraEdge < ropeNeedToJoinAllNetwork) return -1;
        return ropeNeedToJoinAllNetwork;
    }
};