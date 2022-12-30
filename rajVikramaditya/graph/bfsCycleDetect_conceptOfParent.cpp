
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
#define endl "\n"

vi adj[2*100005];
int vis[2*100005];

bool bfsCycleDetect(int root, int par = 0) {
    queue<pair<int, int>> q;
    q.push({root, par});
    vis[root] = 1;
    
    while(!q.empty()) {
        root = q.front().first;
        par = q.front().second;
        q.pop();
        for(auto &it:adj[root]) {
            if(!vis[it]) {
                q.push({it, root});
                vis[it] = 1;
            }
            else if(it != par) return true;
        }    
    }
    return false;
}
int main() {
    int n,m; cin>>n>>m;
    for(int i=1; i<=m; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=m; i++) {
        if(!vis[i]) {
            if(bfsCycleDetect(i) == true) {
                cout<<"cycle exist\n";
                break;
            }
        }
    }
    return 0;
}