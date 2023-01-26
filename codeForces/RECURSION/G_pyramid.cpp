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

// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/G

void star(int n) {
    for(int i=0; i<n; i++) cout<<"*";
}
void space(int n) {
    for(int i=0; i<n; i++) cout<<" ";
}
void f(int n, int row) {
    // base case
    if(row > n) return;
    space(n - row);
    star(2 * row - 1);
    cout<<endl;
    f(n, row + 1);
}
void input() {
   int n; cin>>n;
   f(n, 1);
}

//------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

