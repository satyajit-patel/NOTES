#include<bits/stdc++.h>
#define endl    "\n"
#define MOD     1000000007
#define int     long long int

#define vi      std::vector<int>
#define vvi     std::vector<std::vector<int>>
#define hashMap std::unordered_map<int, int>

#define VIS     std::unordered_map<int, int>
#define ADJ     std::unordered_map<int, std::set<int>>

int mul(int a, int b) {
  return ((a%MOD) * (b%MOD))%MOD;
}

int add(int a, int b) {
  return ((a%MOD) + (b%MOD))%MOD;
}   

int sub(int a, int b) {
  return ((a%MOD) - (b%MOD) + MOD)%MOD;
}

int my_pow(int base, int power) {
  int ans = 1;
  while(power) {
      if(power&1) ans = mul(ans, base);
      base = mul(base, base);
      power >>= 1;
  }
  return ans;
}

int div(int a, int b) {
  int inv_b = my_pow(b, MOD-2);
  return mul(a, inv_b);
}   

int my_gcd(int maxi, int mini) {
  return mini ? my_gcd(mini, maxi%mini) : maxi;
}

int lcm(int a, int b) {
  int x = mul(a, b);
  int y = my_gcd(a, b);
  return div(x, y);
}
vi sievePrime(int n) {
  vi prime(n, 1);
  prime[0] = 0;
  prime[1] = 0;
  for(int i=2; i*i<n; i++) {
      if(prime[i] == 0) continue;
      for(int j=i*i; j<n; j+=i) prime[j] = 0;
  }
  return prime;
}

vi my_fact(int n) {
  vi fact(n+1);
  fact[0] = 1;
  for(int i=1; i<=n; i++) fact[i] = mul(i, fact[i-1]);
  return fact;
}

int nCr(int n, int r) {
  if(r > n) return 0;
  if(n < 0) return 0;
  if(r < 0) return 0;
  if(n == r) return 1;

  vi fact = my_fact(n+1);
  int numo = fact[n];
  int deno = mul(fact[r], fact[n-r]);
  return div(numo, deno);
}

// ------------------------------------------------

// link :  tell if X is an ancestor of Y or not

bool isAncestor(hashMap& in, hashMap& out, int x, int y) {
  if(x == y) return true;
  return in[x]<in[y] && out[y]<out[x];
}

void dfs(int root,ADJ& adj, VIS& vis, vi& euler, hashMap& level, int lev=0) {
  vis[root] = 1;
  level[root] = lev;
  euler.push_back(root);
  for(auto &child : adj[root]) {
    if(!vis[child]) {
      dfs(child, adj, vis, euler, level, lev+1);
      euler.push_back(root);
    }
  }
}

void f(int root, int N, ADJ& adj, int x, int y) {
  hashMap level;
  vi euler;
  VIS vis;
  dfs(root, adj, vis, euler, level);

  hashMap in, out;
  for(int i=0; i<euler.size(); i++) {
    out[euler[i]] = i;
    if(in.find(euler[i]) == in.end()) in[euler[i]] = i;
  }

  int lca = euler[in[x]];
  for(int i=in[x]; i<=in[y]; i++) {
    int midEle = euler[i];
    if(level[midEle] < level[lca]) lca = euler[i];
  }
  if(isAncestor(in,out,x,y)) std::cout<<"yes X is an ancestor of Y\n";
  else std::cout<<"\nnope X is not an ancestor of Y\n";
  std::cout<<"\nsubtre size of root Node is "<<(out[root]-in[root]+2)/2<<"\n";
  std::cout<<"\ndist from x to y is "<<level[x]+level[y]-2*level[lca]<<"\n";
  std::cout<<"\nlca of x and y is "<<lca<<"\n";
}

void input() {
  std::cout<<"Make the Tree\n";
  int N; std::cin>>N;
  ADJ adj;
  for(int i=0; i<N-1; i++) {
    int u, v; std::cin>>u>>v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  std::cout<<"Enter X&Y\n";
  int x, y;
  std::cin>>x>>y;
  std::cout<<"Enter Root\n";
  int root; std::cin>>root;

  f(root, N, adj, x, y);
}

// ---------------------------------------------
signed main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  input();
  return 0;
}
