#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back

//given a tree print path from root to x
vi ans;
vi arr[2*100005];
bool dfs(int root, int parent, int x) {
    ans.pb(root);
    if(root == x) return true;
    
    for(auto &it:arr[root]) {
        if(it != parent) {
            if(dfs(it, root, x) == true) return true;
        }    
    }
    ans.pop_back();
    return false;
}
int main() {
    int n,x; cin>>n>>x;
    for(int i=1; i<= n-1; i++) {
        int u,v; cin>>u>>v;
        arr[u].pb(v);
        arr[v].pb(u);
    }
    bool gotPath = dfs(1,-1,x);
    if(gotPath == false) cout<<"noPath";
    else for(auto &it:ans) cout<<it<<" ";
    return 0;
}