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
  return ((a % MOD) * (b % MOD)) % MOD;
}

int add(int a, int b) { 
  return ((a % MOD) + (b % MOD)) % MOD; 
}

int sub(int a, int b) { 
  return ((a % MOD) - (b % MOD) + MOD) % MOD; 
}

int my_pow(int base, int power) {
  int ans = 1;
  while(power) {
    if(power & 1) ans = mul(ans, base);
    base = mul(base, base);
    power >>= 1;
  }
  return ans;
}

int div(int a, int b) {
  int inv_b = my_pow(b, MOD - 2);
  return mul(a, inv_b);
}

int my_gcd(int a, int b) {
  return a ? my_gcd(b, a % b) : b;
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
  for(int i = 2; i * i < n; i++) {
    if(prime[i] == 0) continue;
    for(int j = i * i; j < n; j += i) prime[j] = 0;
  }
  return prime;
}

vi my_fact(int n) {
  vi fact(n + 1);
  fact[0] = 1;
  for(int i = 1; i <= n; i++) fact[i] = mul(i, fact[i - 1]);
  return fact;
}

int nCr(int n, int r) {
  if(r > n) return 0;
  if(n < 0) return 0;
  if(r < 0) return 0;

  vi fact = my_fact(n + 1);
  int numo = fact[n];
  int deno = mul(fact[r], fact[n - r]);
  return div(numo, deno);
}

// ------------------------------------------------

// link : print path from root till target, if target exist

vi path;
bool dfs2(VIS& vis, ADJ& adj, int x, int root=1) {
  vis[root] = 1;
  path.push_back(root);
  if(root == x) return true;
  for(auto &child : adj[root]) {
    if(!vis[child]) {
      if(dfs2(vis, adj, x, child) == true) return true;
    }
  }
  path.pop_back(); 
  return false;
}

int maxLevel;
int dfs1(VIS& vis, ADJ& adj, int root=1, int lev=0) {
  vis[root] = 1;
  int maxHeight = 0;
  maxLevel = std::max(maxLevel, lev);
  for(auto &child : adj[root]) {
    if(!vis[child])
      maxHeight = std::max(maxHeight, 1 + dfs1(vis, adj, child, lev+1));
  }
  return maxHeight;
}

void input() {
  std::cout<<"enter\n";
  int n;
  std::cin >> n;
  ADJ adj;
  int edge = n-1;
  for(int i=0; i<edge; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  maxLevel = 0;
  VIS vis;
  std::cout<<"maxHeight="<<dfs1(vis, adj)<<endl;
  std::cout<<"maxLevel="<< maxLevel<<endl;
  // trurns out level will be always same as height here
  
  std::cout<<"enter target node\n";
  int x; std::cin>>x;
  vis.clear();
  path.clear();
  if(dfs2(vis, adj, x) == false) std::cout<<"path doesn't exist\n";
  else for(auto &it : path) std::cout<<it<< " ";
}

// ---------------------------------------------
signed main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  input();
  return 0;
}
