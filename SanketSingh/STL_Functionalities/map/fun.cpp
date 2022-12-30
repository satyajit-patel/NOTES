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
    map<char, int> m1;
    m1.insert(make_pair('a', 1));
    m1.insert(make_pair('b', 2));
    m1.insert(make_pair('c', 3));
    m1.insert(make_pair('d', 4));
    for(auto &it : m1) {
        cout<<it.first<<" "<<it.second<<endl;
    }
    //or
    cout<<"----------\n";
    for(auto it=m1.begin(); it != m1.end(); it++) {
        cout<<it->first<<" "<<it->second<<endl;
    }

    /*
    find() --- returns an iterator pointing to that element if present ...else returns end()
    count----->returns +ve value if element is present ..else returns 0
    so if we you want to just check whether a element is present or not its better to use count() and
    if you have to delete the element then use find()
    */

    //access
    cout<<m1.find('a')->second<<endl;
    if(m1.count('a') != 0) cout<<"Present\n";
    else cout<<"Absent\n";

    //delete
    auto it = m1.find('c');
    if(it != m1.end()) m1.erase(it);
    //or
    m1.erase('d');

    for(auto &it : m1) {
        cout<<it.first<<" "<<it.second<<endl;
    }
}
signed main() {
    IOS
    //contestSolve()
    normalSolve();
    return 0;
}