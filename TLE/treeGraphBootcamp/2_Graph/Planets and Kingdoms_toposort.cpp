// link => https://cses.fi/problemset/task/1683/
#include<bits/stdc++.h>
#define vi      std::vector<int>
#define int     long long
#define MOD     1000000007
#define vvi     std::vector<std::vector<int>>
#define vvc     std::vector<std::vector<char>>
#define VIS     std::unordered_map<int, int>
#define ADJ     std::unordered_map<int, std::unordered_set<int>>
// -------------------------------------------------------------------------------------------

// global variable
vi temp;
vvi scc;
std::stack<int> st;

void dfs2(int root, VIS& vis, ADJ& adj) {
    vis[root] = 1;
    temp.push_back(root);
    for(auto& child:adj[root]) if(!vis[child]) dfs2(child, vis, adj);
}

void dfs1(int root, VIS& vis, ADJ& adj) {
    vis[root] = 1;
    for(auto& child:adj[root]) if(!vis[child]) dfs1(child, vis, adj);
    st.push(root);
}

void input() {
   int n, m; std::cin>>n>>m;
   ADJ adj, revAdj;
   while(m--) {
       int u, v; std::cin>>u>>v;
       adj[u].insert(v);
       revAdj[v].insert(u);
   }
   VIS vis;
   for(int root=1; root<=n; root++) if(!vis[root]) dfs1(root, vis, adj);
   vis.clear();
   while(!st.empty()) {
       int root = st.top();
       st.pop();
       if(!vis[root]) {
           dfs2(root, vis, revAdj);
           scc.push_back(temp);
           temp.clear();
       }
   }
   std::cout<<scc.size()<<"\n";
   vi ans(n+1);
   int count = 1;
   for(auto& row:scc) {
       for(auto& it:row) ans[it] = count;
       count++;
   }
   for(int root=1; root<=n; root++) std::cout<<ans[root]<<" ";
}

// -------------------------------------------------------------------------------------------
signed main() {
    input();
	return 0;
}