
//apply dfs when you are eager to try out all paths

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
#define endl "\n"

vi adj[2*100005];
int vis[2*100005];

void dfs(int root) {
    cout<<root<<" ";
    vis[root] = 1;
    
    for(auto &it:adj[root]) {
        if(!vis[it]) dfs(it);
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
            dfs(i);
            connectedComponents++;
        }
    }
    cout<<endl<<connectedComponents<<endl;
    return 0;
}