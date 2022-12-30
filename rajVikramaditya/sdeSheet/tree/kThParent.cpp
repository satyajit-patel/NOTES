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

void dfs(int root, int par, vi adj[], vi &path, vvi &parent) {
    path[root] = root;
    for(auto &it : adj[root]) {
        if(it != par) {
            parent[it][0] = root;
            dfs(it, root, adj, path, parent);
        }
    }
}
void input() {
    // 5
    // 1 2
    // 1 3
    // 3 4
    // 3 5
    // 2
    // 1 5
    // 2 5
    
    int n; cin>>n;
    vector<int> adj[n+1]; //vector of array, n+1 bcz given 1based ind
    for(int i=0; i<n-1; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi path(n+1, -1);
    int maxLevel = log2(n);
    vvi parent(n+1, vi(maxLevel+1, -1));
    //store the immediate parent using dfs
    dfs(1, -1, adj, path, parent);
    //pre computation
    for(int k=1; k<=maxLevel; k++) {
        for(int node=0; node<=n; node++) {
            int v = parent[node][k-1];
            if(v != -1) parent[node][k] = parent[v][k-1];
        }
    }
    
    //finf kTh parent of node x
    int Q; cin>>Q;
    while(Q--) {
        int k,u; cin>>k>>u;
        
        // //this method takes O(N * K)
        // // N for dfs, K for iterartion
        // while(k--) {
        //     u = parent[u];
        // }
        // cout<<u<<endl;   
    
    
        //O(N * log(K)) method
        while(k) {
            //here x is num of set bits in number k
            //that many step we have to cover only 
            int x = std::ceil(std::log2(k));
            u = parent[u][x];
            k -= (1 << x);
        }
        cout<<u<<endl;
    }
}

//------------------------------------------------------------------------
signed main() {
    IOS
    sublimeText();
    input();
    return 0;
}