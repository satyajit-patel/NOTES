// link => https://atcoder.jp/contests/dp/tasks/dp_h
#include<bits/stdc++.h>
#define vi      std::vector<int>
#define int     long long
#define MOD     1000000007
#define vvi     std::vector<std::vector<int>>
#define vvc     std::vector<std::vector<char>>
#define VIS     std::unordered_map<int, int>
#define ADJ     std::unordered_map<int, std::unordered_set<int>>
// -------------------------------------------------------------------------------------------

// global variable
vvi dp;
vvc grid;

int f(int n, int m) {
    // base case
    if(n < 0 || m < 0) return 0;
    if(grid[n][m] == '#') return 0;
    if(n == 0 && m == 0) return 1;
    if(dp[n][m] != -1) return dp[n][m];
    
    // recursive case
    int case1 = f(n-1, m);
    int case2 = f(n, m-1);
    
    // work case
    int ans = (case1 + case2) % MOD;
    
    // return case
    dp[n][m] = ans;
    return ans;
}

void input() {
    int n, m; std::cin>>n>>m;
    grid.resize(n, std::vector<char>(m));
    for(auto &row : grid) for(auto &it : row) std::cin>>it;
    
    dp.resize(n, vi(m, -1));
    int ans = f(n-1, m-1);
    std::cout<<ans<<"\n";
}

// -------------------------------------------------------------------------------------------
signed main() {
    input();
	return 0;
}