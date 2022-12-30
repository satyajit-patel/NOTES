#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back

vi eulerPath;
vi arr[2*100005];
vi level(2*100005);
void dfs(int root, int parent = -1, int lev = 0) {
    level[root] = lev;
    for(auto &it:arr[root]) {
        if(it != parent) dfs(it, root, lev+1);
        //cout<<root<<" ";    
        eulerPath.push_back(root);
    }
}
int main() {
    int n,lca1,lca2; cin>>n>>lca1>>lca2;
    for(int i=1; i<= n-1; i++) {
        int u,v; cin>>u>>v;
        arr[u].pb(v);
        arr[v].pb(u);
    }
    eulerPath.push_back(1);
    dfs(1);
    map<int, int> m;
    for(int i=0; i<eulerPath.size(); i++) {
        if(m[eulerPath[i]] < 1) m[eulerPath[i]] = i;
    }
    //for(auto &it:m) cout<<it.first<<" "<<it.second<<endl;
    int istOccuranceOf_lca1 = m[lca1];
    int istOccuranceOf_lca2 = m[lca2];
    int ans = eulerPath[istOccuranceOf_lca1];
    for(int i=istOccuranceOf_lca1; i<=istOccuranceOf_lca2; i++) {
        if(level[eulerPath[i]] < level[ans]) ans = eulerPath[i];
    }
    cout<<"LCA of "<<lca1<<" & "<<lca2<<" is---> "<<ans<<endl;
    return 0;
}