
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
#define endl "\n"

vi adj[2*100005];
int vis[2*100005];

bool dfsCycleDetect(int root, int par = 0) {
    vis[root] = 1;
    
    for(auto &it:adj[root]) {
        if(!vis[it]) {
            if(dfsCycleDetect(it, root) == true) return true;
        }
        else if(it != par) return true;    
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
            if(dfsCycleDetect(i) == true) {
                cout<<"cycle exist\n";
                break;
            }
        }
    }
    return 0;
}