//link ---> 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vpi vector<pair<int, int>>

vpi adj[100005];
vi col(100005, -1);

bool bfs(int root) {
    col[root] = 0;
    queue<pair<int, int>> q;
    q.push({root, 0});
    
    while(!q.empty()) {
        int node = q.front().first;
        int color = q.front().second;
        q.pop();
        
        for(auto &it : adj[node]) {
            if(col[it.first] == -1) {
                q.push({it.first, !color});
                col[it.first] = !color;
            }
            else if(col[it.first] == color) return false;
        }
    }
    return true;
}
bool dfs(int root, int color = 0) {
    col[root] = color;
    for(auto &it : adj[root]) {
        if(col[it.first] == -1) {
            if(dfs(it.first, !color) == false) return false;
        }
        else if(col[it.first] == color) return false;
    }
    return true;
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
    //if we can color a graph using 2 color such that
    //no adj node have the same color then it's calld bipertie graph
    bool flag = dfs(1);
    //bool flag = bfs(1);
    if(flag == true) cout<<"bipertie\n";
    else cout<<"not bipertie\n";
    return 0;
}