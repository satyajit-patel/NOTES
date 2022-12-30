
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
#define endl "\n"

//-1 ie not visited
//0 ie first color
//1 ie second color 
vi col(1005, -1);
vi adj[100005];
bool dfsCheckBipartite(int root, int color = 0) {   
    col[root] = 0;
    for(auto &it:adj[root]) {
        if(col[it] == -1) {
            if(dfsCheckBipartite(it, !color) == false) return false;
        }
        //if visited then it should't have the same color with adj node
        else if(col[it] == col[root]) return false;
    }
    return true;
}
void graphInput() {
    int n,m; cin>>n>>m;
    for(int i=1; i<=m; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=m; i++) {
        if(col[i] == -1) {
            if(dfsCheckBipartite(i) == false) {
                cout<<"notBipartite or it has odd length cycle\n";
                break;
            }
        }
    }
}
int main() {
    graphInput();
    return 0;
}