#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
#define IOS     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

// ----------------------------------------------------------------------------------------------------

// 

void pattern(int n) {
    /*
            1
           12
          123
         1234
        12345
    */
   for(int i=1; i<=n; i++) {
        string pat = "";
        for(int j=1; j<=n-i; j++) pat += ' ';
        for(int j=1; j<=i; j++) pat += std::to_string(j);
        cout<<pat<<endl;
   }
}

void input() {
   pattern(5);
}

// ----------------------------------------------------------------------------------------------------
signed main() {
    IOS
    input();
    return 0;
}

