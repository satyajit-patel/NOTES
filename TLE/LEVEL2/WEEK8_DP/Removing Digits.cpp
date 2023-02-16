#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>

// ----------------------------------------------------------------------------------------------------

// link:- https://cses.fi/problemset/task/1637

void input() {
    int n; cin>>n;
    int steps = 0;
    while(n > 0) {
        int temp = n;
        int maxEle = -1e9;
        while(temp) {
            int lastDigit = temp % 10;
            maxEle = std::max(maxEle, lastDigit);
            temp /= 10;
        }
        n -= maxEle;
        steps++;
    }
    cout<<steps<<endl;
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    input();
    return 0;
}

