#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
const int MOD = 1e9 + 7;

// ------------------------------------------------

// link:- https://codeforces.com/problemset/problem/71/A

void input() {
  int tc; std::cin>>tc;
  while(tc--) {
    std::string s; std::cin>>s;
    int n = s.size();
    if(n > 10) std::cout<<s[0]<<n-2<<s[n-1]<<endl;
    else std::cout<<s<<endl;
  }
}

// ---------------------------------------------
signed main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  input();
  return 0;
}
