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

// https://cses.fi/problemset/task/1623/

void f(int i, int sum, int totalSum, vi& arr, int& mini) {
    //base case
    int n = arr.size();
    if(i == n) return;

    //include
    f(i+1, sum + arr[i], totalSum, arr, mini);

    //exclude
    f(i+1, sum, totalSum, arr, mini);

    int group1 = sum;
    int group2 = totalSum - sum;
    int diff   = std::abs(group1 - group2);
    mini = std::min(mini, diff);
}
void input() {
    int n; cin>>n;
    vi arr(n);
    for(auto &it : arr) cin>>it;
    int totalSum = 0;
    for(auto &it : arr) totalSum += it;
    int mini = INT_MAX;
    f(0, 0, totalSum, arr, mini);
    cout<<mini<<endl;
}

//------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

