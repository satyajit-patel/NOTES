//link ---> 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vpi vector<pair<int, int>>

int vis[100005];
vpi adj[100005];

vi bfsPath;
void bfs(int root) {
    vis[root] = 1;
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        bfsPath.push_back(node);
        for(auto &it : adj[node]) {
            if(!vis[it.first]) {
                q.push(it.first);
                vis[it.first] = 1;
            }
        }
    }
}
vi dfsPath;
void dfs(int root) {
    dfsPath.push_back(root);
    vis[root] = 1;
    for(auto &it : adj[root]) {
        if(!vis[it.first]) dfs(it.first);
    }
}
void addEdge(int u, int v, bool duplex = false, int w = 0) {
    adj[u].push_back({v, w});
    if(duplex) adj[v].push_back({u, w});
}
int main() {
    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++) {
        int u, v; cin>>u>>v;
        addEdge(u, v, true);
    }
    int connectedComponents = 0;
    for(int i=1; i<=m; i++) {
        if(!vis[i]) {
            dfs(i);
            //bfs(i);
            connectedComponents++;
        }
    }
    cout<<connectedComponents<<endl;
    for(auto &it : dfsPath) cout<<it<<" ";
    //for(auto &it : bfsPath) cout<<it<<" ";
    return 0;
}