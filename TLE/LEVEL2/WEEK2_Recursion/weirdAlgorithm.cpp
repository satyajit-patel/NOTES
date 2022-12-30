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


// https://cses.fi/problemset/task/1068
void f(int n) {
    //base case
    if(n == 1) {
        cout<<n<<" ";
        return;
    }

    cout<<n<<" ";
    if(n%2) f(n*3+1);
    else f(n/2);
}
void input() {
    int n; cin>>n;
    f(n);
}

//------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

