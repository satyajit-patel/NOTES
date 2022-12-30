
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
#define endl "\n"

vi adj[100005];
int vis[100005];
int low[100005];
int timer[100005];
int tim = 0;
void dfsBridges(int root, int parent = 0) {   
    vis[root] = 1;
    timer[root] = low[root] = tim++; 
    for(auto &it:adj[root]) {
        if(it != parent) {
            if(vis[it] == 1) {
                //baseCase
                //i.e cycle so this can't be a bridge
                low[root] = min(low[root], timer[it]);
            }
            else {
                dfsBridges(it, root);
                low[root] = min(low[root], low[it]);
                if(low[it] > timer[root]) cout<<it<<" "<<root<<endl;
            }
        }
    }
}
void graphInput() {
    int n,m; cin>>n>>m;
    for(int i=1; i<=m; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=m; i++) {
        if(!vis[i]) dfsBridges(i);
    }
}
int main() {
    graphInput();
    return 0;
}