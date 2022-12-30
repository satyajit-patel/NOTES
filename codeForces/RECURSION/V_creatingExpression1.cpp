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


// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/V
bool f(int i, int n, int x, int sum, vi& arr) {
    //base case
    if(i == n) {
        if(sum == x) return true;
        return false;
    }

    if(f(i+1, n, x, sum + arr[i], arr)) return true;
    if(f(i+1, n, x, sum - arr[i], arr)) return true;
    return false;
}
void input() {
    int n,x; cin>>n>>x;
    vi arr(n);
    for(auto &it : arr) cin>>it;
    // starting from index 1 becz we can't assign any operator to it as it will be Unary
    if(f(1, n, x, arr[0], arr)) cout<<"YES\n";
    else cout<<"NO\n";
}

//------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

