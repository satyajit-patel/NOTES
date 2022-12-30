//link ---> 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vpi vector<pair<int, int>>

int vis[100005];
vpi adj[100005];

bool dfs(int root) {
    vis[root] = 2;
    for(auto &it : adj[root]) {
        if(!vis[it.first]) {
            if(dfs(it.first) == true) return true;
        }
        else if(vis[it.first] == 2) return true;
    }
    vis[root] = 1;
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
        addEdge(u, v);
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