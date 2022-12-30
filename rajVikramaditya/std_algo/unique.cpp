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
#define     dq      deque<int>
#define     vi      vector<int>
#define     vvi     vector<vector<int>>
void sublimeText() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

//---------------------------------------------------------------------


void input() {
    std::vi arr = {20, 20, 10, 10, 50, 30, 30, 50, 60};
    for(auto &it : arr) cout<<it<<" ";
    cout<<endl;
    
    std::set<int> s;
    s.insert(arr.begin(), arr.end());
    for(auto &it : s) cout<<it<<" ";
    cout<<endl;
    
    vi vec = arr;
    //removes only 2consecutive duplicate element
    auto it = std::unique(vec.begin(), vec.end());
    vec.resize(std::distance(vec.begin(), it));
    for(auto &it : vec) cout<<it<<" ";
    cout<<endl;

    //distance of maxElement from ist element
    int dist = std::distance(arr.begin(), std::max_element(arr.begin(), arr.end()));
    cout<<dist<<endl;
}

//------------------------------------------------------------------------
signed main() {
    IOS
    sublimeText();
    input();
    return 0;
}