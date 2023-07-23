// link => https://atcoder.jp/contests/dp/tasks/dp_i
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
int N;
std::vector<double> A;
std::vector<std::vector<double>> dp;

double f(int n, int H) {
    // base case
    if(n < 0) {
        int T = N - H;
        if(H > T) return 1.0;
        else return 0.0;
    }
    if(dp[n][H] != -1) return dp[n][H];
    
    // recursive case
    double head = f(n-1, H+1) * A[n];
    double tail = f(n-1, H) * (1.0 - A[n]);
    
    // work case
    double ans = head + tail;
    
    // return case
    dp[n][H] = ans;
    return ans;
}

void input() {
    int n; std::cin>>n;
    N = n;
    A.resize(n);
    for(auto &it : A) std::cin>>it;
    
    dp.resize(n+1, std::vector<double>(n+1, -1));
    double ans = f(n-1, 0);
    std::cout<<std::setprecision(12)<<ans<<"\n";
}

// -------------------------------------------------------------------------------------------
signed main() {
    input();
	return 0;
}