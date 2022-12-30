//link ---> 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vpi vector<pair<int, int>>

vpi adj[100005];
vi vis(100005, 0);

stack<int> topoSort;
void dfs(int root) {
    vis[root] = 1;
    for(auto &it : adj[root]) {
        if(!vis[it.first]) dfs(it.first);
    }
    //we backtrack when we have nowhere to go
    //if nowhere to go, push on stack.
    topoSort.push(root);
}
void addEdge(int u, int v, bool undirected = false, int w = 0) {
    adj[u].push_back({v, w});
    if(undirected) adj[v].push_back({u, w});
}
int main() {
    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++) {
        int u, v; cin>>u>>v;
        addEdge(u, v);
    }
    //topoSort is only possible on DAG(directed ascyclic graph)
    for(int i=1; i<=n; i++) {
        if(!vis[i]) dfs(i);
    }
    while(!topoSort.empty()) {
        cout<<topoSort.top()<<" ";
        topoSort.pop();
    }
    return 0;
}