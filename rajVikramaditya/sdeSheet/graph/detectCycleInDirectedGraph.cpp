//link ---> https://bit.ly/3FrzaZp
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vpi vector<pair<int, int>>

bool dfs(int root, vi &vis, vi adj[]) {
    vis[root] = 2;
    for(auto &it : adj[root]) {
        if(!vis[it]) {
            if(dfs(it, vis, adj) == true) return true;
        }
        else if(vis[it] == 2) return true;
    }
    vis[root] = 1;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    // Write your code here.
    vi vis(n+1, 0);
    vi adj[n+1];
    for(auto &it : edges) {
        int u = it.first;
        int v = it.second;
        adj[u].push_back(v);
    }
    bool flag = false;
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            if(dfs(i, vis, adj) == true) {
                flag = true;
                break;
            }
        }
    }
    if(flag == true) return 1;
    else return 0;
}







