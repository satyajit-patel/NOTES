#include<bits/stdc++.h>
#define endl  "\n"
#define MOD   1000000007
#define int   long long int

#define vi    std::vector<int>
#define vvi   std::vector<std::vector<int>>

#define VIS   std::unordered_map<int, int>
#define ADJ std::unordered_map<int, std::set<int>>

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

// link :  find max path. (you can only move right and down)

// clockWise : right, down
int dx[2] = {0, +1};
int dy[2] = {+1, 0};
bool isValid(vvi& mat, int i, int j) {
  return i>=0 && i<mat.size() && j>=0 && j<mat[i].size();
}

int f(vvi& mat) {
  int N = mat.size(), M = mat[0].size();
  int maxSum = INT_MIN;
  std::queue<std::pair<std::pair<int, int>, int>> q;
  q.push({{0, 0}, 0});
  while(!q.empty()) {
    int i = q.front().first.first;
    int j = q.front().first.second;
    int s = q.front().second;
    q.pop();
    if(i==N-1 && j==M-1) maxSum = std::max(maxSum, s);
    for(int ind=0; ind<2; ind++) {
      int ni = i + dx[ind];
      int nj = j + dy[ind];
      if(isValid(mat, ni, nj)) q.push({{ni, nj}, s+mat[ni][nj]});
    }
  }
  return maxSum;
}

void input() {
  vvi mat = {{3, -1, 2, 4, 7}, {-2, 8, 6, 6, 5}, {4, 2, 1, 1, 3}, {-1, 2, -3, 4, 3}};
  int maxSum = INT_MIN, curSum = 0;
  std::cout<<"\nmaxSum = "<<f(mat)<<endl;
}

// ---------------------------------------------
signed main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  input();
  return 0;
}
