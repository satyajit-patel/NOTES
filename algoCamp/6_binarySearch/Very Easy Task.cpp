// link => https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
#include<bits/stdc++.h>
#define int     long long
#define MOD     1000000007
#define vi      std::vector<int>
#define vvi     std::vector<std::vector<int>>
#define vvc     std::vector<std::vector<char>>
#define VIS     std::unordered_map<int, int>
#define ADJ     std::unordered_map<int, std::unordered_set<int>>
// -------------------------------------------------------------------------------------------
// global variable
    
    
// -------------------------------------------------------------------------------------------

bool predicate(int M, int n, int x, int y) {
    int xCopies = M / x;
    int yCopies = M / y;
    // we can create 1 copy at first
    // then we can run the 2 machines at same time to make rest of the copies
    return xCopies + yCopies >= n-1;
}

void input() {
   int n, x, y; std::cin>>n>>x>>y;
   int L = -1, H = std::max(x, y) * n + 1;
   while(H-L >= 2) {
       int M = (L + H) / 2;
       predicate(M, n, x, y) ? H = M : L = M;
   }
   std::cout<<H + std::min(x, y)<<"\n";
}

// -------------------------------------------------------------------------------------------
signed main() {
    input();
	return 0;
}