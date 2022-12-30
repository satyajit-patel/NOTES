
//apply bfs when you just want to rech the destination and every step cost you the same
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
#define endl "\n"

vi adj[2*100005];
int vis[2*100005];

void bfs(int root) {
    queue<int> q;
    q.push(root);
    vis[root] = 1;
    
    while(!q.empty()) {
        root = q.front();
        cout<<root<<" ";
        q.pop();
        for(auto &it : adj[root]) {
            if(!vis[it]) {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
}
int main() {
    int n,m; cin>>n>>m;
    for(int i=1; i<=m; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int connectedComponents = 0;
    for(int i=1; i<=m; i++) {
        if(!vis[i]) {
            bfs(i);
            connectedComponents++;
        }
    }
    cout<<endl<<connectedComponents<<endl;
    return 0;
}