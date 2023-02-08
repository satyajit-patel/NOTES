#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
#define IOS     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

// ----------------------------------------------------------------------------------------------------

// 

int myGcd(int a, int b) {
    // the biggest common nummber thats can divide both of them;
    return (b) ? myGcd(b, a % b) : a;
}

void input() {
   cout<<myGcd(2, 7)<<endl;
   cout<<myGcd(4, 8)<<endl;
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

