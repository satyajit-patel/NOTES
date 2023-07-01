#include<bits/stdc++.h>

#define endl "\n"
#define int long long int
#define vi std::vector<int>
#define vvi std::vector<std::vector<int>>
#define GRAPH std::unordered_map<int, std::set<int>>
const int MOD = 1e9 + 7;

// ------------------------------------------------

// https://atcoder.jp/contests/dp/tasks/dp_a

int f(vi& arr, int i, int N, vi& dp) {
  // base case
  if(i >= N-1) return 0;
  if(dp[i] != -1) return dp[i];

  // recursive case
  int case1 = INT_MAX, case2 = INT_MAX;
  if(i == N-2) case1 = std::abs(arr[i] - arr[i+1]) + f(arr, i+1, N, dp);
  else {
    case1 = std::abs(arr[i] - arr[i+1]) + f(arr, i+1, N, dp);
    case2 = std::abs(arr[i] - arr[i+2]) + f(arr, i+2, N, dp);
  }

  // work case
  int mini = std::min(case1, case2);

  // return case
  dp[i] = mini;
  return mini;
}

void input() {
  int N; std::cin>>N;
  vi arr(N);
  for(auto &it : arr) std::cin>>it;
  vi dp(N+1, -1);
  std::cout<<f(arr, 0, N, dp);
}

// ---------------------------------------------
signed main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  input();
  return 0;
}
