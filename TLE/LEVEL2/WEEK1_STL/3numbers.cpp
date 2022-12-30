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


// https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/Z
void input() {
    int k,s; cin>>k>>s;
    int c = 0;
    for(int x=0; x<=k; x++) {
        for(int y=0; y<=k; y++) {
            int z = s - x - y;
            if(z>=0 && z<=k) c++; 
        }
    }
    cout<<c<<endl;
}

//------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

