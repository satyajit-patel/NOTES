//link ---> 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vpi vector<pair<int, int>>

int vis[100005];
vpi adj[100005];

bool bfs(int root) {
    vis[root] = 1;
    queue<pair<int, int>> q;
    q.push({root, 0});
    while(!q.empty()) {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto &it : adj[node]) {
            if(!vis[it.first]) {
                q.push({it.first, node});
                vis[it.first] = 1;
            }
            else if(it.first != par) return true;
        }
    }
    return false;
}
bool dfs(int root, int par = 0) {
    vis[root] = 1;
    for(auto &it : adj[root]) {
        if(!vis[it.first]) {
            if(dfs(it.first, root) == true) return true;
        }
        else if(it.first != par) return true;
    }
    return false;
}
void addEdge(int u, int v, bool undirected = false, int w = 0) {
    adj[u].push_back({v, w});
    if(undirected) adj[v].push_back({u, w});
}
int main() {
    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++) {
        int u, v; cin>>u>>v;
        addEdge(u, v, true);
    }
    bool flag = false;
    for(int i=1; i<=m; i++) {
        if(!vis[i]) {
            if(dfs(i) == true) {
                flag = true;
                break;
            }
        }
    }
    if(flag == true) cout<<"cycle\n";
    else cout<<"no cycle\n";
    return 0;
}