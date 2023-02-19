#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
const int MOD = 1e9 + 7;

// ----------------------------------------------------------------------------------------------------

// link:- https://www.codechef.com/submit/LSUM

vi addBig(vi& x, vi& y) {
    vi ans;
    std::reverse(x.begin(), x.end());
    std::reverse(y.begin(), y.end());
    int mxLen = std::min(x.size(), y.size());
    int carry = 0;
    for(int i=0; i<mxLen; i++) {
        int value = x[i] + y[i] + carry;
        int digit = value % 10;
        ans.push_back(digit);
        carry = value / 10;
    }
    if(x.size() > mxLen) {
        for(int i=mxLen; i<x.size(); i++) {
            int value = x[i] + carry;
            int digit = value % 10;
            ans.push_back(digit);
            carry = value / 10;
        }
    }
    if(y.size() > mxLen) {
        for(int i=mxLen; i<y.size(); i++) {
            int value = y[i] + carry;
            int digit = value % 10;
            ans.push_back(digit);
            carry = value / 10;
        }
    }
    while(carry) {
        int digit = carry % 10;
        ans.push_back(digit);
        carry /= 10;
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

void input() {
    int tc; cin>>tc;
    while(tc--) {
        string a,b; cin>>a>>b;
        vi x,y;
        for(int i=0; i<a.size(); i++) x.push_back(a[i] - '0');
        for(int i=0; i<b.size(); i++) y.push_back(b[i] - '0');
        vi ans = addBig(x, y);
        for(int i=0; i<ans.size(); i++) cout<<ans[i];
        cout<<endl;
    }
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    input();
    return 0;
}

