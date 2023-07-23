// link => https://atcoder.jp/contests/dp/tasks/dp_k
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
vi A;
int mini, dp[100006];

bool f(int stones) {
    // base case
    if(stones < mini) return false;
    if(dp[stones] != -1) return dp[stones];
    
    // recursive case
    // if we can give other person a loosing state then we win
    // else other person will win
    for(auto &it : A) {
        if(it <= stones) {
            if(f(stones-it) == false) {
                dp[stones] = true;
                return true; // we don't have to explore more... we did it
                
            }
        }
    }
    
    // return case
    dp[stones] = false;
    return false;
}

void input() {
    int n, stones; std::cin>>n>>stones;
    A.resize(n);
    for(auto &it : A) std::cin>>it;
    mini = *std::min_element(A.begin(), A.end());
    
    std::memset(dp, -1, sizeof dp);
    bool win = f(stones);
    win ? std::cout<<"First\n" : std::cout<<"Second\n";
}

// -------------------------------------------------------------------------------------------
signed main() {
    input();
	return 0;
}