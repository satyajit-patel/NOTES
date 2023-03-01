// https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?leftPanelTab=1
#include<bits/stdc++.h>
#define ADJ unordered_map<int, set<int>>
#define VIS unordered_map<int, bool>
class DSU {
public:
    vector<int> par;
    vector<int> rank;
    DSU(int n) {
        par.resize(n+1);
        rank.resize(n+1);
        for(int i=0; i<=n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }
    int findPar(int node) {
        if(node == par[node]) return node;
        return par[node] = findPar(par[node]);
    }
    void unionR(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        if(pu == pv) return;
        if(rank[pu] < rank[v]) par[pu] = pv;
        else if(rank[pv] < rank[pu]) par[pv] = pu;
        else {
            par[pu] = pv;
            rank[pv]++;
        }
    }
};
string cycleDetection (vector<vector<int>>& edges, int n, int m) {
    // prepare adj list
    DSU dsu(n);
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        if(dsu.findPar(u) == dsu.findPar(v)) return "Yes";
        dsu.unionR(u, v);
    }
    
    /*
    int cc = 0;
    for(int i=1; i<=n; i++) {
        if(dsu.par[i] == i) cc++;
    }
    */
    
    return "No";
}