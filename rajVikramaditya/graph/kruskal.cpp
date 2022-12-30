
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
#define endl "\n"

struct node {
    int u, v, w;
    node(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool comp(node p1, node p2) {
    return p1.w < p2.w;
}
class DSU {
private:
    vi par, size;
public:
    DSU(int n) {
        par.resize(n);
        size.resize(n);
        for(int i=0; i<=n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }
    int findPar(int node) {
        if(node == par[node]) return node;
        return par[node] = findPar(par[node]);
    }
    void unionS(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        if(pu == pv) return;
        if(size[pu] < size[pv]) {
            par[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            par[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
int main() {
    int n, m; cin>>n>>m;
    vector<node> edges;
    for(int i=0; i<m; i++) {
        int u, v, w; cin>>u>>v>>w;
        edges.push_back(node(u, v, w));
    }
    sort(edges.begin(), edges.end(), comp);
    DSU dsu(n);
    int ans =0;
    for(auto &it : edges) {
        int u = it.u;
        int v = it.v;
        int w = it.w;
        if(dsu.findPar(u) != dsu.findPar(v)) {
            ans += w;
            dsu.unionS(u, v);
        }
    }
    cout<<ans<<endl;
    return 0;
}