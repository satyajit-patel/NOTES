//https://www.codingninjas.com/codestudio/problems/kruskal-s-minimum-spanning-tree-algorithm_1082553?leftPanelTab=1
#include <bits/stdc++.h> 
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
bool comp(vector<int>& a, vector<int>& b) {
    return (a[2] < b[2]);
}
int kruskalMST(int n, int m, vector<vector<int>>& graph) {
	std::sort(graph.begin(), graph.end(), comp);
    DSU dsu(n);
    int minWeight = 0;
    for(int i=0; i<graph.size(); i++) {
        int u = graph[i][0];
        int v = graph[i][1];
        int w = graph[i][2];
        if(dsu.findPar(u) != dsu.findPar(v)) {
            minWeight += w;
            dsu.unionR(u, v);
        }
    }
    return minWeight;
}