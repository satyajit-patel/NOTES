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

// https://codeforces.com/contest/1770/problem/A

void input() {
    int tc; cin>>tc;
    while(tc--) {
        int n,m; cin>>n>>m;
        priority_queue<int> pq;
        while(n--) {
            int x; cin>>x;
            pq.push(x * -1);
        }
        while(m--) {
            int x; cin>>x;
            pq.pop();
            pq.push(x * -1);
        }
        int ans = 0;
        while(!pq.empty()) {
            int x = pq.top() * -1;
            pq.pop();
            ans += x;
        }
        cout<<ans<<endl;
    }
}

//------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

