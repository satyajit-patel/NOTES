// link => https://atcoder.jp/contests/dp/tasks/dp_l
#include<bits/stdc++.h>
#define vi      std::vector<int>
#define int     long long
#define MOD     1000000000
#define vvi     std::vector<std::vector<int>>
#define vvc     std::vector<std::vector<char>>
#define VIS     std::unordered_map<int, int>
#define ADJ     std::unordered_map<int, std::unordered_set<int>>
// -------------------------------------------------------------------------------------------

// global variable
vi A;
int dp[3001][3001][2];

int f(int i, int j, int turn) {
    // base case
    if(i == j) { // single element
        if(turn) return A[i];
        return 0;
    }
    if(dp[i][j][turn] != -1) return dp[i][j][turn];
    
    // recursive case
    int ans = 0;
    if(turn) {
        int case1 = A[i] + f(i+1, j, !turn);
        int case2 = A[j] + f(i, j-1, !turn);
        ans = std::max(case1, case2); // maximize
    }
    else {
        int case1 = 0 + f(i+1, j, !turn);
        int case2 = 0 + f(i, j-1, !turn);
        ans = std::min(case1, case2); // minimize
    }
    
    // return case
    dp[i][j][turn] = ans;
    return ans;
}

void input() {
  int n; std::cin>>n;
  A.resize(n);
  for(auto& it:A) std::cin>>it;
   
  int totalScore = 0;
  for(auto& it : A) totalScore += it;
  
  std::memset(dp, -1, sizeof dp);
  int player1Score = f(0, n-1, 1);
  
  int player2Score = totalScore - player1Score;
  int ans = player1Score - player2Score;
  std::cout<<ans<<"\n";
}

// -------------------------------------------------------------------------------------------
signed main() {
    input();
	return 0;
}