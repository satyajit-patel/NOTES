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


// https://codeforces.com/contest/71/problem/A
void input() {
	int n; cin>>n;
	while(n--) {
		string s; cin>>s;
		if(s.size() <= 10) cout<<s<<endl;
		else {
			// //s.substr(startIndex, substringSize);
			// string temp = s.substr(1, s.size()-1);

			int n = s.size();
			n -= 2;
			string temp = to_string(n);

			string ans = "";
			ans += s.front();
			ans += temp;
			ans += s.back();
			cout<<ans<<endl;
		}
	}
}

//------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

