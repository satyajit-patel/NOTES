//Link=> https://codeforces.com/contest/1760/problem/E?f0a28=1

#include<bits/stdc++.h>
using namespace std;
#define log(args...)    { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl; void err(istream_iterator<string> it) {}
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
#define     vpi     vector<pair<int, int>>

//---------------------------------------------------------------------

int f(vi &arr) {
    int zero = 0, ans = 0;

    // //O(N^2)
    // for(int i=0; i<arr.size(); i++) {
    //     if(arr[i] == 1) {
    //         for(int j=i+1; j<arr.size(); j++) {
    //             if(arr[j] == 0) ans++;
    //         }
    //     }
    // }

    //O(N)
    for(int i=arr.size()-1; i>=0; i--) {
        if(arr[i] == 0) zero++;
        else ans += zero;
    }

    return ans;
}
void input() {
   int n; cin>>n;
   vi arr(n);
   for(auto &it : arr) cin>>it;

   //just count num of zeros for each 1's that will be the num of inversin in binary array 
   int ans = f(arr); //1 operation
   for(int i=0; i<n; i++) {
        if(arr[i] == 0) {
            arr[i] = 1;
            ans = max(ans, f(arr)); //either this
            arr[i] = 0;
            break; //as we are allowed to do only 2 operation
        }
   }
   for(int i=n-1; i>=0; i--) {
        if(arr[i] == 1) {
            arr[i] = 0;
            ans = max(ans, f(arr)); //or this
            arr[i] = 1;    
            break;
        }
   }
   cout<<ans<<endl;
}

//------------------------------------------------------------------------
signed main() {
    IOS
    int tc; cin>>tc;
    while(tc--) input();
    return 0;
}

