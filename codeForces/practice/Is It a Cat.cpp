#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
const int MOD = 1e9 + 7;

// ----------------------------------------------------------------------------------------------------

// link:- https://codeforces.com/contest/1800/problem/A

bool isCat(std::string& s) {
    for(auto &it : s) it = std::tolower(it);
    std::string cat = "meow";
    std::string tmp = "";
    char ch = 'A';
    for(auto &it : s) {
        if(it != ch) {
            tmp += it;
            ch = it;
        }
    }
    return tmp == cat;
}

void input() {
    int tc; cin>>tc;
    while(tc--) {
        int n; cin>>n;
        std::string s; std::cin>>s;
        if(isCat(s)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    input();
    return 0;
}