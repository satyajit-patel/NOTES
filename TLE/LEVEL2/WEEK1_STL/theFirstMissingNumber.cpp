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
#define     vpi     vector<pair<int, int>>

//---------------------------------------------------------------------


// https://codeforces.com/group/c3FDl9EUi9/contest/262795/problem/D
bool comp(int a, int b) {
    return (a < b);
}
void input() {
    int n,m; cin>>n>>m;
    vector<int> vec(n);
    for(auto &it : vec) cin>>it;

    vector<int> range(2*m+1);
    std::iota(range.begin(), range.end(), -m);
    //logarr(range, 0, range.size()-1);

    std::sort(vec.begin(), vec.end(), comp);
    for(auto &it : range) {
        if(std::find(vec.begin(), vec.end(), it) == vec.end()) {
            cout<<it<<endl;
            break;
        }
    }
}

//------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

