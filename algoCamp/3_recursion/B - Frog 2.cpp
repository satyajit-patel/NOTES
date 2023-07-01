#include<bits/stdc++.h>

#define endl "\n"
#define int long long int
#define vi std::vector<int>
#define vvi std::vector<std::vector<int>>
#define GRAPH std::unordered_map<int, std::set<int>>
const int MOD = 1e9 + 7;

// ------------------------------------------------

// https://atcoder.jp/contests/dp/tasks/dp_b

int f(vi& arr, int K, int i, int N, vi& dp) {
  // base case
  if(i >= N-1) return 0;
  if(dp[i] != -1) return dp[i];

  // recursive case
  int mini = INT_MAX;
  for(int step=1; step<=K; step++) {
    if(i+step >= N) break;
    mini = std::min(mini, std::abs(arr[i]-arr[i+step])+f(arr, K, i+step, N, dp));
  }

  // return case
  dp[i] = mini;
  return mini;
}

void input() {
  // std::cout<<"enter\n";
  int N, K; std::cin>>N>>K;
  vi arr(N);
  for(auto &it : arr) std::cin>>it;
  vi dp(N+1, -1);
  std::cout<<f(arr, K, 0, N, dp);
}

// ---------------------------------------------
signed main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  input();
  return 0;
}
