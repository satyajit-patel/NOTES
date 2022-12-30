
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
#define endl "\n"

stack<int> st;
vi adj[100005];
int vis[100005];
void printTopoSort() {
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
void dfsTopoSort(int root) {   
    vis[root] = 1;
    for(auto &it:adj[root]) {
        if(!vis[it]) dfsTopoSort(it);
    }
    //if nowhere to go, put on stack and backtrack
    st.push(root);
}
void graphInput() {
    int n,m; cin>>n>>m;
    for(int i=1; i<=m; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1; i<=m; i++) {
        if(!vis[i]) dfsTopoSort(i);
    }
    printTopoSort(); //directed acyclic graph
}
int main() {
    graphInput();
    return 0;
}