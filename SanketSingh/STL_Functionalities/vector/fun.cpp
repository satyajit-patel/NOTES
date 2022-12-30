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
    //2d vector
    vector<vector<int>> vec(5, vector<int>(10, 9));
    int row = vec.size();
    int col = vec[0].size();
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }

    //1d vector
    /*
    int n; cin>>n;
    vector<int> v1(n);
    for(int &it : v1) cin>>it;
    vector<int> v2;
    for(int i=0; i<n; i++) {
        int x; cin>>x;
        v2.push_back(x);
    }
    */
    vector<int> v1 = {5, 4, 3, 2, 1};
    vector<int> v2 = {1, 2, 3, 4, 5};
    
    sort(v1.begin(), v1.end());
    int n = v1.size();
    log(v1.front(), v1.back());
    vector<int> temp = v1;
    v1.clear();
    cout<<v1.empty()<<"\n";
    v1 = temp;
    logarr(v1, 0, n-1);
    v1.erase (v1.begin()+2);
    for(auto &it : v1) cout<<it<<" ";
    cout<<"\n"<<(v1 == v2)<<"\n";

}
signed main() {
    IOS
    //contestSolve()
    normalSolve();
    return 0;
}