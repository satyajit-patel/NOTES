// link => https://atcoder.jp/contests/dp/tasks/dp_f
#include<bits/stdc++.h>
using namespace std;
#define int long long
// -------------------------------------------------------------------------------------------

// global variable
string a, b;
string lcsText;

// offcourse this will TLE but aim is too focus on logic

void f(int n, int m, string s) {
    // base case
    if(n < 0 || m < 0) {
        if(s.size() > lcsText.size()) lcsText = s;
        return;
    }
    
    // recursive case
    if(a[n] == b[m]) {
        s += a[n];
        f(n-1, m-1, s);
        s.pop_back();
    }
    else f(n-1, m, s), f(n, m-1, s);
}

void input() {
    cin>>a>>b;
    int n = a.size(), m = b.size();
    lcsText = "";
    string s = "";
    f(n-1, m-1, s);
    reverse(lcsText.begin(), lcsText.end());
    cout<<lcsText<<"\n";
}

// -------------------------------------------------------------------------------------------
signed main() {
    input();
	return 0;
}