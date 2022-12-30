//link ---> https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vpi vector<pair<int, int>>

void dfs(int root, vector<int> &vis, vector<int> adj[], vector<int> &ans) {
    ans.push_back(root);
    vis[root] = 1;
    for(auto &it : adj[root]) {
        if(!vis[it]) dfs(it, vis, adj, ans);
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    vector<int> ans;
    vector<int> vis(V+1, 0);
    for(int i=0; i<V; i++) {
        if(!vis[i]) dfs(i, vis, adj, ans);
    }
    return ans;
}