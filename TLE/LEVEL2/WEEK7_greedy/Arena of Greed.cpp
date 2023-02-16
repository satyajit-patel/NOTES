#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>

// ----------------------------------------------------------------------------------------------------

// link:- https://codeforces.com/problemset/problem/1425/A

void input() {
    int tc; cin>>tc;
    while(tc--) {
        int n; cin>>n;
        int mine = 0, opponent = 0;
        bool turn = true;
        while(n) {
            if(n%2 == 0 && (n%4 || n == 4)) {
                if(turn) mine += n/2;
                else opponent += n/2;
                n /= 2;
            }
            else {
                if(turn) mine += 1;
                else opponent += 1;
                n -= 1;
            }
            turn = !turn;
        }
        cout<<mine<<endl;
    }
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    input();
    return 0;
}

