#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
const int MOD = 1e9 + 7;

// ------------------------------------------------

// link:- sort in decreasing order but if there's a draw, then use lowest value of second as priority

static bool comp(std::pair<int, int>& p1, std::pair<int, int>& p2) {
  if(p1.first == p2.first) return p1.second < p2.second;
  return p1.first > p2.first;
}

void input() {
  std::vector<std::pair<int, int>> vec = {{-1,100}, {1,3}, {2, 1}, {1,1}};
  std::sort(vec.begin(), vec.end(), comp);
  for(auto &it : vec) cout<<"{"<<it.first<<","<<it.second<<"}"<<" ";
}

// ---------------------------------------------
signed main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  input();
  return 0;
}