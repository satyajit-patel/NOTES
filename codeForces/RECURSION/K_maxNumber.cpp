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

// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/K

void f(int i, vi& arr, int& maxi) {
    // base case
    if(i >= arr.size()) return;

    maxi = std::max(maxi, arr[i]);
    f(i+1, arr, maxi);
}
void input() {
   int n; cin>>n;
   vi arr(n);
   for(auto &it : arr) cin>>it;
   int maxi = INT_MIN;
    f(0, arr, maxi);
    cout<<maxi<<endl;
}

//------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

