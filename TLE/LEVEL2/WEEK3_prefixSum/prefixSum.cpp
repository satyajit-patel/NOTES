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

// https://cses.fi/problemset/task/1646
vi f(vi&arr, int N) {
    vi temp(N);
    temp[0] = arr[0];
    for(int i=1; i<N; i++) {
        temp[i] = temp[i-1] + arr[i];
    }
    return temp;
}
void input() {
    int N,Q; cin>>N>>Q;
    vi arr(N);
    for(auto &it : arr) cin>>it;
    vi prefixSum = f(arr, N);
    while(Q--) {
        int L,R; cin>>L>>R;
        // given 1 based indexing
        L--;
        R--;
        int ans = prefixSum[R];
        if(L != 0) ans -= prefixSum[L-1];
        cout<<ans<<endl;
    }
}

//------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

