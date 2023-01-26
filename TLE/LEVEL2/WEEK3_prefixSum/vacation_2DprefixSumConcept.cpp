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

// https://www.codechef.com/ZCOPRAC/problems/ZCO22001

vvi f(int n, int m, vvi& A) {
    vvi P(n+1, vi(m+1));
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) P[i][j] = P[i-1][j] + P[i][j-1] + A[i][j] - P[i-1][j-1];
    }
    return P;
}
void input() {
    int n,m; cin>>n>>m;
    vvi A(n+1, vi(m+1));
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) cin>>A[i][j];
    }

    vvi P = f(n, m, A);

    int Q; cin>>Q;
    while(Q--) {
        int L,R,i,j; cin>>L>>R>>i>>j;
        int length = i - L + 1; 
        int height = j - R + 1;
        int totalSquare = length * height;

        int ans = P[i][j] - P[L-1][j] - P[i][R-1] + P[L-1][R-1];

        if(ans == totalSquare) cout<<1<<endl;
        else cout<<0<<endl;
    }
}

//------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

