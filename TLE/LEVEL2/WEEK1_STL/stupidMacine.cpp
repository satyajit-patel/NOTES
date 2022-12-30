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


// https://www.codechef.com/LRNDSA02/problems/STUPMACH?tab=statement
void input() {
    int tc; cin>>tc;
	while(tc--) {
	    int n; cin>>n;
	    std::vector<int> vec(n);
	    for(auto &it : vec) cin>>it;
	    
	    //10^9 * 10^6 = 10^15 (ie exceeding int limit)
	    int ans     = 0;
	    int mini    = INT_MAX;
	    for(auto &it : vec) {
	        mini = std::min(mini, it);
	        ans += mini;
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

