#include<bits/stdc++.h>
using namespace std;
#define log(args...)    { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << endl;
    err(++it, args...);
}
#define     IOS     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define     endl    "\n" 
#define     int     long long int
#define     vi      vector<int>
#define     dq      deque<int>
#define     vvi     vector<vector<int>>
void sublimeText() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

//---------------------------------------------------------------------

int timer = 0;
void dfs(int root, int par, vi adj[], vi &path, vi &inTime, vi &outTime) {
    path[root] = root;
    inTime[root] = ++timer;
    for(auto &it : adj[root]) {
        if(it != par) dfs(it, root, adj, path, inTime, outTime);
    }
    outTime[root] = ++timer;
}
void input() {
    // 5
    // 1 2
    // 1 3
    // 3 4
    // 3 5
    // 2
    // 3 5
    // 5 3
    // 2
    // 3
    // 2
    int n; cin>>n;
    vector<int> adj[n+1]; //vector of array, n+1 bcz given 1based ind
    for(int i=0; i<n-1; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi path(n+1);
    vi inTime(n+1);
    vi outTime(n+1);
    dfs(1, -1, adj, path, inTime, outTime);

    // for(auto &it : path) cout<<it<<" ";
    // cout<<endl;
    // for(auto &it : inTime) cout<<it<<" ";
    // cout<<endl;
    // for(auto &it : outTime) cout<<it<<" ";
    // cout<<endl;
    
    //find is node U is an ancestor of node V
    int Q; cin>>Q;
    while(Q--) {
        int u,v; cin>>u>>v;
        if(inTime[u] < inTime[v] && outTime[u] > outTime[v]) cout<<"yes\n";
        else cout<<"no\n";    
    }
    //find num of nodes in a subtree
    int q; cin>>q;
    while(q--) {
        int node; cin>>node;
        int ans = (outTime[node]-inTime[node]+1)/2;
        cout<<ans<<endl;
    }
}

//------------------------------------------------------------------------
signed main() {
    IOS
    sublimeText();
    input();
    return 0;
}