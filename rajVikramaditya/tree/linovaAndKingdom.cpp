
//https://codeforces.com/problemset/problem/1336/A

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
#define endl "\n"

vi adj[2*100005];
int level[2*100005];
int parent[2*100005][17];
int subtreeSize[2*100005];

int findKthParent(int node, int k) {
    int power = 0;
    while(k) {
        if(k&1) node = parent[node][power];
        power++;
        k = k >> 1;
    }
    return node;
}
int linova(int n, int k) {
    priority_queue<int> pq;
    for(int i=1; i<=n; i++) {
        pq.push(level[i] - (subtreeSize[i]-1));
    }
    int ans = 0;
    while(k--) {
        ans += pq.top();
        pq.pop();
    }
    return ans;
}
void dfs(int root, int par = 0, int lev = 0) {
    level[root] = lev;
    subtreeSize[root] = 1;
    parent[root][0] = par;
    for(int i=1; i<17; i++) parent[root][i] = parent[parent[root][i-1]][i-1];
    
    for(auto &it:adj[root]) {
        if(it != par) dfs(it, root, lev+1);
    }
}
int main() {
    int n,k; cin>>n>>k;
    for(int i=1; i<=n-1; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout<<linova(n, k)<<endl;
    //cout<<findKthParent(6, 1)<<endl;
    return 0;
}