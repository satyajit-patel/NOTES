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


// https://codeforces.com/contest/1175/problem/B

void input() {
    int x = 0;
    stack<int> st;
    st.push(1);
    int INF = (1ll << 32);

    int tc; cin>>tc;
    while(tc--) {
        string s; cin>>s;
        if(s == "add") x += st.top();
        else if(s == "end") st.pop();
        else if(s == "for") {
            int n; cin>>n;
            st.push(std::min(INF, n * st.top()));
        }
        
    }
    if(x >= INF) cout<<"OVERFLOW!!!"<<endl;
    else cout<<x<<endl;
}

//------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

