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
    vector<int> vec = {5, 10, 155, 20, 20, 20};
    int n = vec.size();
    int gcd = __gcd(abs(vec[0]), abs(vec[1]));
    int lcm = (vec[0]*vec[1])/gcd;
    log(gcd, lcm);
    logarr(vec, 0, n-1);
    reverse(vec.begin(), vec.end());
    logarr(vec, 0, n-1);
    auto it = max_element(vec.begin(), vec.end());
    cout<<*it<<endl;

    bool flag = binary_search(vec.begin(), vec.end(), 20);
    log(flag);
    int idx = lower_bound(vec.begin(), vec.end(), 20) - vec.begin();
    int idx2 = upper_bound(vec.begin(), vec.end(), 20) - vec.begin();
    int freq = (idx2 - idx);
    log(vec[idx], vec[idx2], freq);

    vector<int> v = {1, 3, 2};
	sort(v.begin(), v.end());
	do {
		for(auto &it : v) cout<<it;
		cout<<endl;
	}
	while(next_permutation(v.begin(), v.end()));
}
signed main() {
    IOS
    //contestSolve()
    normalSolve();
    return 0;
}