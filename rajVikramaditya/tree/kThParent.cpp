#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

vi adj[2*100005];
int parent[2*100005][17];

int power(int base, int power) {
    int ans = 1;
    while(power) {
        if(power&1) {
            ans = (ans*base) % int(1e9+7);
            power -= 1;
        }
        else {
            base = (base*base) % int(1e9+7);
            power /= 2;
        }
    }
    return ans;
}
int findKthParent(int node, int k) {
    int cnt = 0;
    while(k) {
        if(k&1) {
            //cout<<power(2, cnt)<<" ";
            node = parent[node][cnt];
        }
        cnt++;
        k = k >> 1;
    }
    return node;
}
void dfs(int root, int par = 0) {
    //cout<<root<<" ";
    parent[root][0] = par;
    for(int i=1; i<17; i++) {
        parent[root][i] = parent[parent[root][i-1]][i-1];
    }
    
    for(auto &it:adj[root]) {
        if(it != par) dfs(it, root);
    }
}
int main() {
    int n,x,k; cin>>n>>x>>k;
    for(int i=1; i<=n-1; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout<<findKthParent(x, k);
    return 0;
}