#include<bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long int
#define vi      vector<int>
#define vvi     vector<vector<int>>
const int MOD = 1e9 + 7;

// ------------------------------------------------

// link:- 

class Demo {
public: 
  int val;
  int operator+(Demo& object2) {
    int val1 = this->val;
    int val2 = object2.val;
    return val1 * val2;
  }
};

void input() {
  Demo object1, object2;
  object1.val = 2;
  object2.val = 5;
  int ans = object1 +(object2);
  // obj1 acting as current object
  // + acting as function call
  // obj2 acting as object parameter
  cout<<ans<<endl;
}

// ---------------------------------------------
signed main() {
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    input();
    return 0;
}
