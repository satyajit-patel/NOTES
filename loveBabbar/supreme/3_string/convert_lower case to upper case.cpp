#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
const int MOD = 1e9 + 7;

// ----------------------------------------------------------------------------------------------------

// link:- 


void input() {
  string s = "happyandsad";
  cout<<s<<endl;
  // for(auto &it : s) it = std::toupper(it);
  for(auto &it : s) it = it - 'a' + 'A';
  cout<<s<<endl;
  // for(auto &it : s) it = std::tolower(it);
  for(auto &it : s) it = it - 'A' + 'a';
  cout<<s<<endl;
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    input();
    return 0;
}
