#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
const int MOD = 1e9 + 7;

// ------------------------------------------------

// link:-

int getHash(string s) {
  int h = 0;
  for(auto &ch : s) h = ((h * 31) + (ch - 'a' + 1)) % MOD;
  return h;
}

void input() {
  cout<<(getHash("abc") == getHash("abc"))<<endl;
}

// ---------------------------------------------
signed main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  input();
  return 0;
}
