#include<bits/stdc++.h>
using namespace std;


#define log(args...)    { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << endl;
    err(++it, args...);
}




#define     IOS     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define     endl    "\n" 
#define     int     long long int
#define     vi      vector<int>
#define     vvi     vector<vector<int>>
#define     vvc     vector<vector<char>>
#define     vpi     vector<pair<int, int>>
#define     M       (int)1e9+7

//---------------------------------------------------------------------

// https://cses.fi/problemset/task/1652

vvi f(int N, vvi& A) {
    vvi P(N+1, vi(N+1));
    for(int i=1; i<N+1; i++) {
        for(int j=1; j<N+1; j++) P[i][j] = P[i-1][j] + P[i][j-1] + A[i][j] - P[i-1][j-1];
    }
    return P;
}
void input() {
    int N,Q; cin>>N>>Q;
    vvi grid(N+1, vi(N+1, 0));
    for(int i=1; i<N+1; i++) {
        for(int j=1; j<N+1; j++) {
            char ch; cin>>ch;
            if(ch == '*') grid[i][j] = 1;
        }
    }
    vvi P = f(N, grid);
    while(Q--) {
        int L,R,i,j; cin>>L>>R>>i>>j;
        int tree = P[i][j] - P[L-1][j] - P[i][R-1] + P[L-1][R-1];
        cout<<tree<<endl;
    }
}

//------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

