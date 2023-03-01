#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
const int MOD = 1e9 + 7;

// ----------------------------------------------------------------------------------------------------

// link:- https://atcoder.jp/contests/abc284/tasks/abc284_c

class DSU {
public:
    vector<int> parent, height;
    DSU(int n) {
        parent.resize(n, -1);
        height.resize(n, -1);
    }

    int findParent(int u) {
        if(parent[u] == -1) return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionByHeight(int u, int v) {
        int x = findParent(u);
        int y = findParent(v);
        if(x == y) return;

        if(height[x] < height[y]) parent[x] = y;
        else if(height[y] < height[x]) parent[y] = x;
        else {
            parent[x] = y;
            height[y]++;
        }
    }
};

void dfs(int root, unordered_map<int, bool>& vis, unordered_map<int, set<int>>& adj) {
    vis[root] = true;
    for(auto &child : adj[root]) {
        if(!vis[child]) dfs(child, vis, adj);
    }
}

void input() {
//    int n,m; cin>>n>>m;
//    // prepare an adj list
//    unordered_map<int, set<int>> adj;
//    for(int i=0; i<m; i++) {
//         int u,v; cin>>u>>v;

//         adj[u].insert(v);
//         adj[v].insert(u);
//    }
//    int cc = 0;
//    unordered_map<int, bool> vis;
//    for(int i=1; i<=n; i++) {
//         if(!vis[i]) {
//             cc++;
//             dfs(i, vis, adj);
//         }
//    } 
//    cout<<cc<<endl;

    int n,m; cin>>n>>m;
    // given 1 based indexing
    DSU dsu(n+1);
    for(int i=0; i<m; i++) {
        int u,v; cin>>u>>v;
        dsu.unionByHeight(u, v);
    }
    int cc = 0;
    for(int i=1; i<=n; i++) {
        if(dsu.findParent(i) == i) cc++;
    }
    cout<<cc<<endl;
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    input();
    return 0;
}