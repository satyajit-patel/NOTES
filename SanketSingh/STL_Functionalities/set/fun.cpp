#include<bits/stdc++.h>

using namespace std;
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}

#define     IOS     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define     int     long long int
#define     vi      vector<int>
#define     endl    "\n" 
void contestSolve() {
    int tc; cin>>tc;
    while(tc--) {
        
    }
}
void normalSolve() {
    set<int> s;
    for(int i =1; i<=5; i++) {
        s.insert(i*10);
    }
    for(auto &it : s) cout<<it<<" ";
}
signed main() {
    IOS
    //contestSolve()
    normalSolve();
    return 0;
}