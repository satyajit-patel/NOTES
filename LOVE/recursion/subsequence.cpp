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

#define     dq      deque<int>
#define     vi      vector<int>
#define     vvi     vector<vector<int>>
#define     vpi     vector<pair<int, int>>

//---------------------------------------------------------------------


void subsequence(int i, string str, string ans) {
    if(i == str.size()) {
        cout<<ans<<" ";
        return;
    }
    //include
    subsequence(i+1, str, ans + str[i]);
    //exclude
    subsequence(i+1, str, ans);
}
void input() {
    string str = "1234";
    string ans = "";
    subsequence(0, str, ans);
}

//------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

