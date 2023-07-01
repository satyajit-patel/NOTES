#include<bits/stdc++.h>

#define endl "\n"
#define int long long int
#define vi std::vector<int>
#define vvi std::vector<std::vector<int>>
#define pb push_back
#define GRAPH std::unordered_map<int, std::set<int>>
const int MOD = 1e9 + 7;

namespace my {
  void dfs(int root, GRAPH& adj, vi& vis, std::map<int, int>& inTime, std::map<int, int>& outTime, int& time) {
    vis[root] = 1;
    inTime[root] = time++;
    for(auto &child : adj[root]) {
      if(!vis[child]) dfs(child, adj, vis, inTime, outTime, time);
    }
    outTime[root] = time++;
  }
}

// ------------------------------------------------

// link :- tell if X is an ancestor of Y or not

void input() {
  std::cout<<"Enter\n";
  int N; std::cin>>N;
  GRAPH adj;
  vi vis(N, 0);
  for(int i=0; i<N-1; i++) {
    int u, v; std::cin>>u>>v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  std::cout<<"Enter X&Y\n";
  int x, y;
  std::cin>>x>>y;

  int time = 0;
  std::map<int, int> inTime, outTime;
  my::dfs(0, adj, vis, inTime, outTime, time);
  std::cout<<inTime[x]<<" "<<outTime[x]<<endl;
  std::cout<<inTime[y]<<" "<<outTime[y]<<endl;
  if(inTime[x]<inTime[y] && inTime[y]<outTime[y] && outTime[y]<outTime[x]) std::cout<<"yes\n";
  else std::cout<<"nope X is not an ancestor of Y\n";
}

// ---------------------------------------------
signed main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  input();
  return 0;
}
