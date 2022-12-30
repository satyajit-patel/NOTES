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


// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/I
bool isVowel(char ch) {
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
    if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return true;
    return false;
}
int f(int i, string& s) {
    //base case
    if(i == s.size()) return 0;

    int yes = 0;
    int no  = 0;
    if(isVowel(s[i]) && i < s.size()) yes = 1 + f(i+1, s);
    else no = 0 + f(i+1, s);

    int ans = yes + no;
    return ans;
}
void input() {
    string s; std::getline(cin, s);
    cout<<f(0, s)<<endl;
}

//------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

