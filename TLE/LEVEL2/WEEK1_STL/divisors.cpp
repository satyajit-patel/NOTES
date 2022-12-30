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


// codeforces.com/group/MWSDmqGsZm/contest/219432/problem/K
bool comp(int a, int b) {
    return (a<b);
}
void input() {
    int n; cin>>n;

    // //O{N}
    // for(int i=1; i<=n; i++) if(n%i == 0) cout<<i<<endl; 

    //O(sqrt(N))
    vector<int> ans;
    for(int i=1; i*i<=n; i++) {
        //if number is divisible
        //then both reminder and quotient are the factors
        if(n%i == 0) {
            ans.push_back(i);
            if(i != n/i) ans.push_back(n/i);
        }
    }
    std::sort(ans.begin(), ans.end(), comp);
    //logarr(ans, 0, ans.size()-1);
    for(auto &it : ans) cout<<it<<endl;
}

//------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

